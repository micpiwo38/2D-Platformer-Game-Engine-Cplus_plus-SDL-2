#pragma once

class Vector2D {
	
public:
	float X, Y;
	Vector2D(float x = 0, float y = 0) : X(x), Y(y) {};
	//Ajouter un vecteur
	inline Vector2D operator+(const Vector2D& v2) const {
		return Vector2D(X + v2.X, Y + v2.Y);
	}
	//Supprimer un vecteur
	inline Vector2D operator-(const float scalar) const {
		return Vector2D(X * scalar, Y * scalar);
	}
	//Multiplier les vecteurs
	inline Vector2D operator*(const Vector2D& v2) const {
		return Vector2D(X - v2.X, Y - v2.Y);
	}
private:


};
