#include "Tool.hpp"
#include "MapCase.hpp"

namespace Tool {
	sf::Vector2f toWindowCoord(const float &x, const float &y, const bool with_transformation)
	{
		return sf::Vector2f(
			x * (calcWidthAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE) / 2) - (calcWidthAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE) / 2 * y),
			(x + y) * (calcHeightAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE) * (with_transformation ? 1 : RESIZE_TILE_Y)) / 2
		);
	}

	sf::Vector2i toDataCoord(const float &x, const float &y, const bool with_transformation)
	{
		float tileX = calcWidthAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE);
		float tileY = calcHeightAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE);
		float new_y = (-x + ((y * 2) / (tileY * (with_transformation ? 1 : RESIZE_TILE_Y)) * (tileY / 2))) / ((tileY / 2) + (tileX / 2));

		return sf::Vector2i(
			(int)(((2 * y) - new_y * (tileY * (with_transformation ? 1 : RESIZE_TILE_Y))) / (tileY * (with_transformation ? 1 : RESIZE_TILE_Y))),
			(int)new_y
		);
	}

	sf::Vector2f toDataCoordF(const float & x, const float & y, const bool with_transformation)
	{
		float tileX = calcWidthAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE);
		float tileY = calcHeightAfterRotation(SIZE_TILE_X, SIZE_TILE_Y, ROTATION_TILE);
		float new_y = (-x + ((y * 2.f) / (tileY * (with_transformation ? 1.f : RESIZE_TILE_Y)) * (tileY / 2.f))) / ((tileY / 2.f) + (tileX / 2.f));

		return sf::Vector2f(
			((2 * y) - new_y * (tileY * (with_transformation ? 1.f : RESIZE_TILE_Y))) / (tileY * (with_transformation ? 1.f : RESIZE_TILE_Y)),
			new_y
			);
	}

	float toDegree(const float &a)
	{
		return a / M_PI * 180;
	}

	float toRad(const float &a)
	{
		return a / 180 * M_PI;
	}

	float abs(const float &number)
	{
		if (number < 0) {
			return number * -1;
		}
		return number;
	}

	// Min = 0 : Max = 2
	float getPercentageDarknessFromTime(const float &time)
	{
		return (-cos(M_PI * time / DAY_DURATION_SECONDS) + 1);
	}

	sf::Vector2f calcSizeAfterRotation(const float &width, const float &height, const float &angle_deg)
	{
		return sf::Vector2f(
			calcWidthAfterRotation(width, height, angle_deg),
			calcHeightAfterRotation(width, height, angle_deg)
		);
	}

	float calcWidthAfterRotation(const float &width, const float &height, const float &angle_deg)
	{
		return width * cos(toRad(angle_deg)) + height * sin(toRad(angle_deg));
	}

	float calcHeightAfterRotation(const float &width, const float &height, const float &angle_deg)
	{
		return width * sin(toRad(angle_deg)) + height * cos(toRad(angle_deg));
	}

	sf::Color getAverageColorShadowTile()
	{
		sf::VertexArray &vertex = DataContainer::getInstance()->map->getShadowTile();
		sf::Color color;

		color.r = (vertex[0].color.r + vertex[1].color.r + vertex[2].color.r + vertex[3].color.r) / 4;
		color.g = (vertex[0].color.g + vertex[1].color.g + vertex[2].color.g + vertex[3].color.g) / 4;
		color.b = (vertex[0].color.b + vertex[1].color.b + vertex[2].color.b + vertex[3].color.b) / 4;

		return color;
	}

	bool isInBoundDataCoord(const sf::Vector2i &position, const sf::Vector2i &min_position, const sf::Vector2i &max_position)
	{
		return (position.x > min_position.x && position.y > min_position.y && position.x < max_position.x && position.y < max_position.y);
	}

	float pythagore_hypothenuse(float & a, float & b)
	{
		return sqrt(a*a + b*b);
	}

	bool collide_something(MapCase *_case, const sf::Vector2f &coord, bool recursive) {
		if (!_case) {
			return false;
		}
		
		sf::Rect<float> hitbox_character;
		sf::Rect<float> hitbox_item;

		float size_texture = DataContainer::getInstance()->main_character->getSizeTexture().x * DataContainer::getInstance()->main_character->getScale().x / SIZE_TILE_X * SCALE_TEXTURE_TO_HITBOX;
		hitbox_character.left = coord.x - size_texture / 2;
		hitbox_character.top = coord.y - size_texture / 2;
		hitbox_character.width = size_texture;
		hitbox_character.height = size_texture;

		for (std::list<IObject *>::iterator obj = _case->getListCharacterOn().begin(); obj != _case->getListCharacterOn().end(); ++obj) {
			size_texture = (*obj)->getSizeTexture().x * (*obj)->getScale().x / SIZE_TILE_X * SCALE_TEXTURE_TO_HITBOX;
			hitbox_item.left = (*obj)->_position.x - size_texture / 2;
			hitbox_item.top = (*obj)->_position.y - size_texture / 2;
			hitbox_item.width = size_texture;
			hitbox_item.height = size_texture;

			if (hitbox_character.intersects(hitbox_item)) {
				return true;
			}
		}

		if (recursive) {
			return collide_something(_case->up(), coord) || collide_something(_case->left(), coord) || collide_something(_case->right(), coord) || collide_something(_case->bottom(), coord);
		}
		return false;
	}
}