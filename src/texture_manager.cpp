#include "../headers/texture_manager.h"
#include "../headers/engine.h"
#include <iostream>

//Engine* Engine::s_Instance = nullptr;
TextureManager* TextureManager::s_Instance = nullptr;

bool TextureManager::LoadTexture(std::string id, std::string file_name)
{
	SDL_Surface* surface = IMG_Load(file_name.c_str());
	if (surface == nullptr) {
		std::cout << "Erreur de chargement de l'image %s, %s\n"<< file_name.c_str() << SDL_GetError() << std::endl;
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
	if (texture == nullptr) {
		std::cout << "Erreur de creation de la texture %s, %s\n" << file_name.c_str() << SDL_GetError() << std::endl;
		return false;
	}
	m_TextureMap[id] = texture;
	if (texture) {
		return true;
	}
	else {
		DropTexture(id);
	}
	return true;
}

void TextureManager::DropTexture(std::string id)
{
	SDL_DestroyTexture(m_TextureMap[id]);
	m_TextureMap.erase(id);
}
//A la fermeture du programme
void TextureManager::Clean()
{
	
	std::map<std::string, SDL_Texture*>::iterator it;
	for (it = m_TextureMap.begin(); it != m_TextureMap.end(); it++) {
		SDL_DestroyTexture(it->second);
	}
	m_TextureMap.clear();
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect source_rect = { 0, 0, width, height };
	SDL_Rect destination_rect = { x, y, width, height };
	//Ex ajoute la rotation
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &source_rect, &destination_rect, 0, nullptr, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
	SDL_Rect source_rect = { width * frame, height * (row - 1), width, height};
	SDL_Rect destination_rect = { x, y, width, height };
	//Ex ajoute la rotation
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &source_rect, &destination_rect, 0, nullptr, flip);
}
