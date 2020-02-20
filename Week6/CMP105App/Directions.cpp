#include "Directions.h"
#include <iostream>
using namespace std;

Directions::Directions() {

}

void Directions::handleInput(float dt) {
	target = sf::Vector2f(input->getMouseX(), input->getMouseY());
}

void Directions::update(float dt) {
	acceleration = 50.f;
	direction = sf::Vector2f(target - getPosition());
	direction = Vector::normalise(direction);
	setVelocity(getVelocity() + (direction * acceleration * dt));
	setPosition(getPosition() + (getVelocity() * dt));

	if (Vector::magnitude(target - getPosition()) < 10.f){
		setPosition(target);
		setVelocity(0, 0);
	}
}