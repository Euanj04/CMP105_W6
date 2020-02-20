#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Directions :
	public GameObject
{
public:
	Directions();
	void handleInput(float dt);
	void update(float dt);

	sf::Vector2f target;
	sf::Vector2f direction;
	float acceleration;
};

