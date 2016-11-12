#pragma once
#include <fstream>

class AFileManager
{
public:
	AFileManager();
	~AFileManager();

	virtual void			openFile(const std::string &) = 0;
	virtual void			closeFile();
	void					trim(std::string &);
	std::string				getValueFromKey(std::string &, const std::string) const;

protected:
	std::fstream			_file;
};

