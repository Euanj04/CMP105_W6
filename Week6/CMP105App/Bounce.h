#pragma once
#include "Framework/GameObject.h"
#include "SFML/Graphics.hpp"
class Bounce :
	public GameObject
{
public:
	Bounce();
	void update(float dt);
	void handleInput(float dt);
	void setWindow(sf::RenderWindow* win) { window = win; };

	float gravity;
	float scale;
protected:
	sf::RenderWindow* window;
};

