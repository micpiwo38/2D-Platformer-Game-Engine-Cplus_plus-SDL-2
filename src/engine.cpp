#include "../headers/engine.h"
#include <iostream>
#include "../headers/texture_manager.h"
#include "../headers/vector2D.h"
#include "../headers/transform.h"
#include "../headers/player.h"

Engine* Engine::s_Instance = nullptr;
Player* player = nullptr;

bool Engine::Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 && IMG_Init(IMG_INIT_PNG) != 0) {
		std::cout << "Erreur de la SDL %s\n" << SDL_GetError() << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow("C++ SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (m_window == nullptr) {
		std::cout << "Erreur création de la fenetre %s\n" << SDL_GetError() << std::endl;
		return false;
	}

	m_render_surface = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_render_surface == nullptr) {
		std::cout << "Erreur création du rendu de la fenetre %s\n" << SDL_GetError() << std::endl;
		return false;
	}

	//Test image
	TextureManager::GetInstance()->LoadTexture("player", "assets/player_idle.png");
	player = new Player(new Properties("player", 100, 200, 64, 64));

	return m_isRunning = true;
}

bool Engine::Clean() {
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_render_surface);
	SDL_DestroyWindow(m_window);
	IMG_Quit();
	SDL_Quit();
	m_isRunning = true;
	return m_isRunning;
}

void Engine::Quit() {
	m_isRunning = false;
}

void Engine::Update() {
	player->Update(2);
}
void Engine::Render() {
	SDL_SetRenderDrawColor(m_render_surface, 120, 40, 40, 255);
	SDL_RenderClear(m_render_surface);
	//Appel de la methode Draw du texture manager 
	player->Draw();
	SDL_RenderPresent(m_render_surface);
}
void Engine::Events() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		Quit();
		break;
	default:
		break;
	}
}