#pragma once
#include <string>

namespace Wolf
{
	struct DirectoryInformation
	{
		std::string filename;
		std::string fileType;
		std::string absolutePath;

		bool isFile;

	public:
		DirectoryInformation(std::string fname, std::string fType, std::string absPath, bool isF)
		{
			filename = fname;
			fileType = fType;
			absolutePath = absPath;
			isFile = isF;

		}
	};
}