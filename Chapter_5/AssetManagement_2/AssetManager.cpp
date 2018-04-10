#include "AssetManager.h"
#include <assert.h>

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
	//Only allow one AssetManager to exist
	//Otherwise throw an exception
	assert(sInstance == nullptr);
	sInstance = this;
}

sf::Texture& AssetManager::GetTexture(std::string const& filename)
{
	auto& texMap = sInstance->m_Textures;

	//See if the texture is already loaded
	auto pairFound = texMap.find(filename);
	//If yes, return the texture
	if (pairFound != texMap.end())
	{
		return pairFound->second;
	}
	else //Else, load the texture and return it
	{
		//Create an element in the texture map
		auto& texture = texMap[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}

sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string const& filename)
{
	auto& sBufferMap = sInstance->m_SoundBuffers;

	auto pairFound = sBufferMap.find(filename);
	if (pairFound != sBufferMap.end())
	{
		return pairFound->second;
	}
	else
	{
		//Create an element in the SoundBuffer map
		auto& sBuffer = sBufferMap[filename];
		sBuffer.loadFromFile(filename);
		return sBuffer;
	}
}

sf::Font& AssetManager::GetFont(std::string const& filename)
{
	auto& fontMap = sInstance->m_Fonts;

	auto pairFound = fontMap.find(filename);
	if (pairFound != fontMap.end())
	{
		return pairFound->second;
	}
	else
	{
		//Create an element in the Fonts map
		auto& font = fontMap[filename];
		font.loadFromFile(filename);
		return font;
	}
}

