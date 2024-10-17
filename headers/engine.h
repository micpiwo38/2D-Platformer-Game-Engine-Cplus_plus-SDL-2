#pragma once 

#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class Engine {
public:
	
	static Engine* GetInstance() {
		//Singleton
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
	}

	bool Init();
	bool Clean();
	void Quit();

	void Update();
	void Render();
	void Events();

	inline bool IsRunning() { return m_isRunning; };
	inline SDL_Renderer *GetRenderer() {
		return m_render_surface;
	}
	
private:
	
	SDL_Window* m_window = NULL;
	SDL_Renderer* m_render_surface = NULL;
	bool m_isRunning = true;
	static Engine* s_Instance;
};