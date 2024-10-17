#pragma once

#include "game_object.h"
#include <string>

class  Character : public GameObject
{
public:
	 Character(Properties* props) : GameObject(props){}
	 virtual void Draw() = 0;
	 virtual void Clean() = 0;
	 virtual void Update(float deltatime) = 0;
	

protected:
	std::string m_name;

};


