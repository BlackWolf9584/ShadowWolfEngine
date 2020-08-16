#pragma once
#include "AssetTypes.h"
#include <filesystem>
#include "DirectoryInformation.h"


namespace Wolf
{
	class AssetManager
	{
	public:
		static std::string ParseFilename(std::string const& str, const char delim, std::vector<std::string>& out);
		static std::string ParseFiletype(std::string filename);

		static void ProcessAseets(std::string assetType);
		static void InitiateAssetConversion(std::string assetPath, std::string conversionType);

		static std::vector<DirectoryInformation> GetFsContents();
		static std::vector<DirectoryInformation> ReadDirectory(std::string path);
		static std::string GetParentPath(std::string path);

		static bool MoveFile(std::string filePath, std::string movePath);

	private:
		void ImportAsset(std::string assetPath, std::string assetName);
	};

}