#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class MapCase;

#define DAY_DURATION_SECONDS 300
#define SIZE_TILE_X 100
#define SIZE_TILE_Y 100
#define RESIZE_TILE_X 1
#define RESIZE_TILE_Y 0.55f
#define SCALE_TEXTURE_TO_HITBOX 0.8f
#define ROTATION_TILE 45
#define DEPTH_SIZE 10
#define TEXTURE_SET_NAME "SET_NAME="
#define WINDOW_NAME "Creons un jeu S01"

#define HEIGHT_DIALOG_PERCENTAGE		20
#define WIDTH_DIALOG_TEXT_PERCENTAGE	50
#define HEIGHT_DIALOG_TEXT_PERCENTAGE	14
#define OFFSETX_DIALOG_TEXT_PERCENTAGE	25
#define OFFSETY_DIALOG_TEXT_PERCENTAGE	83
#define HEIGHT_DIALOG_IMAGE_PERCENTAGE	16
#define WIDTH_DIALOG_IMAGE_PERCENTAGE	16
#define OFFSETX_DIALOG_IMAGE_PERCENTAGE	4.5f
#define OFFSETY_DIALOG_IMAGE_PERCENTAGE	82

#define M_PI 3.14159265358979323846

#define WINDOW_DEFAULT		0
#define WINDOW_TO_DELETE	1

namespace Tool
{
	// Coord translation
	sf::Vector2f	toWindowCoord(const float &x, const float &y, const bool with_transformation = false);
	sf::Vector2i	toDataCoord(const float &x, const float &y, const bool);
	sf::Vector2f	toDataCoordF(const float &x, const float &y, const bool);

	// Angle conversion
	float			toDegree(const float &);
	float			toRad(const float &);

	// Numeric operations
	float			abs(const float &);
	float			getPercentageDarknessFromTime(const float &);
	float			getHeightDialogWindow();
	sf::Vector2i	getSizeDialogWindowText();
	sf::Vector2i	getPositionDialogWindowText();
	sf::Vector2f	getSizeDialogWindowImage();
	sf::Vector2f	getPositionDialogWindowFirstImage();
	sf::Vector2f	getPositionDialogWindowSecondImage();

	// Calculate
	sf::Vector2f	calcSizeAfterRotation(const float &, const float &, const float &);
	float			calcWidthAfterRotation(const float &, const float &, const float &);
	float			calcHeightAfterRotation(const float &, const float &, const float &);
	sf::Color		getAverageColorShadowTile();

	// Hitbox
	bool			isInBoundDataCoord(const sf::Vector2i &, const sf::Vector2i &, const sf::Vector2i &);
	bool			collide_something(MapCase *, const sf::Vector2f &, bool recursive = false);

	// Geometry
	float			pythagore_hypothenuse(float &a, float &b);
};