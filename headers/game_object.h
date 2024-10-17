#pragma once

#include "object.h"
#include "transform.h"
#include <string>
#include <SDL.h>

struct Properties
{
public :
	//Contruteur struct
	Properties(std::string textureID, float x, float y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE) {
		X = x;
		Y = y;
		Flip = flip;
		Width = width;
		Height = height;
		TextureID = textureID;
	}
public:
	std::string TextureID;
	int Width, Height;
	float X, Y;
	SDL_RendererFlip Flip;
};

//Herite de IObject
class  GameObject : public IObject
{
public:
	//Le constructeur de la classe prend en paramètre la struct Properties => qui  a également un constructeur
	GameObject(Properties* props): m_textureID(props->TextureID), m_width(props->Width), m_height(props->Height), m_flip(props->Flip) {
		m_transform = new Transform(props->X, props->Y);
	};


	virtual void Draw() = 0;
	virtual void Update(float deltatime) = 0;
	virtual void Clean() = 0;

protected:
	Transform* m_transform;
	int m_width, m_height;
	std::string m_textureID;
	SDL_RendererFlip m_flip;
	

private:

};


