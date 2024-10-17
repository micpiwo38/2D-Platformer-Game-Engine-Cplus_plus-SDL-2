#pragma once

class IObject {
public:
	//Classe abstraite
	virtual void Draw() = 0;
	virtual void Update(float deltatime) = 0;
	virtual void Clean() = 0;


private:
};