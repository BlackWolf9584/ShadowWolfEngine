#pragma once

namespace Wolf
{
	class AssetTypes
	{
	private:
		static inline std::vector<std::string> assetTypes = {
			"fbx", "obj", "wav", "cs", "png", "blend", "hazel", "ogg"
		};

	public:
		AssetTypes();
		static int GetParsedAssetID(std::string extension);
	};

}