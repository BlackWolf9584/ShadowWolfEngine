#include "SWpch.h"
#include "AssetManager.h"

namespace Wolf
{
	void AssetManager::ProcessAseets(std::string assetType)
	{
		std::vector<std::string> tokenizedAssetData;
		auto filename = ParseFilename(assetType, '\\', tokenizedAssetData);
		auto filetype = ParseFiletype(filename);

		if (filetype == "blend") {
			SW_CORE_WARN("Initiating Asset Conversion");
			InitiateAssetConversion(assetType, "FBX");
		}
	}

	void AssetManager::InitiateAssetConversion(std::string assetPath, std::string conversionType)
	{
		/* Create a filestream to write a blender python script for conversion of the asset */
		/* The 'bpy.ops.export_scene.(asset-type-to-convert) function runs blender in background and exports the file' */
		std::string path = std::filesystem::temp_directory_path().string();
		std::ofstream fileStream(path + "export.py");

		/* Importing the python modules required for the export to work out */
		fileStream << "import bpy\n";
		fileStream << "import sys\n";

		/* Branch for detecting the conversion type (this one for FBX) */
		if (conversionType == "FBX") {
			fileStream << "bpy.ops.export_scene.fbx(filepath=r'" + path + "asset.fbx" + "', axis_forward='-Z', axis_up='Y')\n";
		}

		/* Branch for detecting the conversion type (this one for OBJ) */
		if (conversionType == "OBJ") {
			fileStream << "bpy.ops.export_scene.obj(filepath=r'" + path + "asset.obj" + "', axis_forward='-Z', axis_up='Y')\n";
		}

		/* Closing the filesteam */
		fileStream.close();

		/* This section involves creating the command to export the .blend file to the required asset type */
		/* The command goes something like this.. */
		/* blender.exe D:\Program Files\cube.blend --background --python D:\Program Files\export.py */

		std::string blender_base_path = "C:\\Program Files\\Blender Foundation\\Blender 2.82\\blender.exe";
		std::string p_asset_path = '"' + assetPath + '"';
		std::string p_blender_path = '"' + blender_base_path + '"';
		std::string p_script_path = '"' + path + "export.py" + '"';

		/* Creating the actual command that will execute */
		std::string convCommand = '"' + p_blender_path + " " + p_asset_path + " --background --python " + p_script_path + "" + '"';

		/* Just for debugging(it took me 1hr for this string literals n stuff! It better work!) */
		SW_CORE_INFO(convCommand.c_str());

		/* Fire the abov`e created command */
		system(convCommand.c_str());
	}

	std::vector<DirectoryInformation> AssetManager::GetFsContents()
	{
		std::string path = "assets";
		int counter = 0;
		std::vector<DirectoryInformation> dInfo;

		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			bool isDir = std::filesystem::is_directory(entry);

			auto dir_data = ParseFilename(entry.path().string(), '\\', std::vector<std::string>());
			if (isDir) {
				DirectoryInformation d(dir_data, ".hazel", entry.path().string(), false);
				dInfo.push_back(d);
			}
			else {
				DirectoryInformation d(dir_data, ".hazel", entry.path().string(), true);
				dInfo.push_back(d);
			}
		}

		return dInfo;
	}

	std::vector<DirectoryInformation> AssetManager::ReadDirectory(std::string path)
	{
		int counter = 0;
		std::vector<DirectoryInformation> dInfo;

		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			bool isDir = std::filesystem::is_directory(entry);

			auto dir_data = ParseFilename(entry.path().string(), '\\', std::vector<std::string>());

			if (isDir) {
				DirectoryInformation d(dir_data, ".ShadowWolfEngine", entry.path().string(), false);
				dInfo.push_back(d);
			}
			else {
				DirectoryInformation d(dir_data, ".Playground", entry.path().string(), true);
				dInfo.push_back(d);
			}
		}
		return dInfo;
	}

	std::string AssetManager::GetParentPath(std::string path)
	{
		auto p = std::filesystem::path(path);
		return p.parent_path().string();
	}

	bool AssetManager::MoveFile(std::string filePath, std::string movePath)
	{
		std::string s = "move " + filePath + " " + movePath.c_str();
		system(s.c_str());

		std::vector<std::string> data;

		if (std::filesystem::exists(std::filesystem::path(movePath + "\\" + ParseFilename(filePath, '\\', data)))) {
			return true;
		}
		else {
			return false;
		}
	}

	void AssetManager::ImportAsset(std::string assetPath, std::string assetName)
	{
	}

	std::string AssetManager::ParseFilename(std::string const& str, const char delim, std::vector<std::string>& out)
	{
		size_t start;
		size_t end = 0;

		while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
		{
			end = str.find(delim, start);
			out.push_back(str.substr(start, end - start));
		}

		return out[out.size() - 1];
	}

	std::string AssetManager::ParseFiletype(std::string filename)
	{
		size_t start;
		size_t end = 0;
		std::vector<std::string> out;

		while ((start = filename.find_first_not_of(".", end)) != std::string::npos)
		{
			end = filename.find(".", start);
			out.push_back(filename.substr(start, end - start));
		}

		return out[out.size() - 1];
	}
}