#include "../headers/player.h"
#include "../headers/texture_manager.h"
#include <SDL.h>
#include "../headers/transform.h"


Player::Player(Properties* props) : Character(props)
{
	m_rigidbody = new Rigidbody();
	m_animation = new Animation();
	m_animation->SetProps(m_textureID, 1, 2, 200, SDL_FLIP_HORIZONTAL);
	std::cout << "Erreur : %s\n" << SDL_GetError() << std::endl;
}


void Player::Draw() {
	m_animation->Draw(m_transform->X, m_transform->Y, m_width, m_height);
}


void Player::Update(float deltatime) {
	m_rigidbody->Update(0.2);
	m_transform->TranslateX(m_rigidbody->Position().X);
	m_transform->TranslateY(m_rigidbody->Position().Y);
	m_animation->Update();
}

void Player::Clean() {
	TextureManager::GetInstance()->Clean();
}