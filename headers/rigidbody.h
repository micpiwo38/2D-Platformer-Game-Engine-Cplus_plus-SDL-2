#pragma once

#include "vector2D.h"

//const
#define UNI_MASS 1.0f
#define GRAVITY 9.8f;

#define FORWARD 1
#define BACKWARD -1

#define UPWARD -1
#define DOWNWARD 1


class Rigidbody {
public:
	Rigidbody() {
		m_mass = UNI_MASS;
		m_gravity = GRAVITY;
	};
	//SETTERS
	inline void SetMass(float mass) {
		m_mass = mass;
	}
	inline void SetGravity(float gravity) {
		m_gravity = gravity;
	}


	//FORCES
	inline void ApplyForce(Vector2D F) {
		m_force = F;
	}
	//Force horizontal
	inline void ApplyForceX(float Fx) {
		m_force.X = Fx;
	}
	inline void ApplyForceY(float Fy) {
		m_force.Y = Fy;
	}
	//UNSET FORCE
	inline void UnsetForce() {
		m_force = Vector2D(0, 0);
	}
	//Friction
	inline void ApplyFriction(Vector2D Fr) {
		m_friction = Fr;
	}
	//Unset Friction
	inline void UnsetFriction() {
		m_friction = Vector2D(0, 0);
	}

	//GETTERS
	inline float GetMass() {
		return m_mass;
	}

	inline Vector2D Position() {
		return m_position;
	}

	inline Vector2D Velocity() {
		return m_velocity;
	}

	inline Vector2D Acceleration() {
		return m_acceleration;
	}
	


	void Update(float deltatime) {
		m_acceleration.X = (m_force.X + m_friction.X) / m_mass;
		m_acceleration.Y = m_gravity + m_force.Y / m_mass;
		m_velocity = m_acceleration * deltatime;
		m_position = m_velocity * deltatime;
	}

private:
	float m_mass;
	float m_gravity;

	Vector2D m_force; //x et Y
	Vector2D m_friction; // ice => water <=> friction

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
};
