#include "SWpch.h"
#include "AssetTypes.h"

namespace Wolf
{
	int AssetTypes::GetParsedAssetID(std::string extension)
	{
		for (int i = 0; i < assetTypes.size(); i++)
		{
			if (extension == assetTypes[i])
			{
				return i;
			}
		}

		return -1;
	}
}