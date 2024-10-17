#include "../headers/player.h"
#include "../headers/texture_manager.h"
#include <SDL.h>
#include "../headers/transform.h"
#include "../headers/input.h"


Player::Player(Properties* props) : Character(props)
{
	m_rigidbody = new Rigidbody();
	m_animation = new Animation();
	
	m_animation->SetProps(m_textureID, 1, 2, 200);
}


void Player::Draw() {
	m_animation->Draw(m_transform->X, m_transform->Y, m_width, m_height);
}


void Player::Update(float deltatime) {
	
	m_animation->SetProps("player_idle", 1, 2, 200);
	
	m_rigidbody->UnsetForce();

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
		m_rigidbody->ApplyForceX(5 * BACKWARD);
		m_animation->SetProps("player_run", 1, 3, 100, SDL_FLIP_HORIZONTAL);
	}

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
		m_rigidbody->ApplyForceX(5 * FORWARD);
		m_animation->SetProps("player_run", 1, 3, 100);
		
	}
	

	m_rigidbody->Update(0);
	m_transform->TranslateX(m_rigidbody->Position().X);
	//m_transform->TranslateY(m_rigidbody->Position().Y);
	m_animation->Update();
	
}

void Player::Clean() {
	TextureManager::GetInstance()->Clean();
}