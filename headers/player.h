#pragma once

#include "character.h"
#include "animation.h"
#include <string>
#include "rigidbody.h"

class Player : public Character {

public:
	
	Player(Properties* props);
	virtual void Draw();
	virtual void Clean();
	virtual void Update(float deltatime);

protected:

protected:
	Animation* m_animation;
	Rigidbody* m_rigidbody;

};