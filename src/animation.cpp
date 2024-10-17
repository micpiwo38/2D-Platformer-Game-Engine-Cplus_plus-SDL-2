#include "../headers/animation.h"
#include "../headers//texture_manager.h"



void Animation::Update() {
	m_sprite_frame = (SDL_GetTicks() / m_anim_speed) % m_frame_count;
}


void Animation::SetProps(std::string textureID, int sprite_row, int frame_count, int anim_speed, SDL_RendererFlip flip) {
	m_textureID = textureID;
	m_sprite_row = sprite_row;
	m_frame_count = frame_count;
	m_anim_speed = anim_speed;
	m_flip = flip;
}

void Animation::Draw(int x, int y, int sprite_width, int sprite_height) {
	TextureManager::GetInstance()->DrawFrame(m_textureID, x, y, sprite_width, sprite_height, m_sprite_row, m_sprite_frame, m_flip);
}

