#pragma once
#include <string>
#include <SDL.h>

class Animation {
public:
	
	void Update();
	void Draw(int x, int y, int sprite_width, int sprite_height);
	void SetProps(std::string textureID, int sprite_row, int frame_count, int anim_speed, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	int m_sprite_row, m_sprite_frame;
	int m_anim_speed, m_frame_count;
	std::string m_textureID;
	SDL_RendererFlip m_flip;
	
};