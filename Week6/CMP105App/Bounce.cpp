#include "Bounce.h"

Bounce::Bounce() {
	gravity = 9.8;
	scale = 50;
}

void Bounce::update(float dt) {
	setVelocity(getVelocity().x, getVelocity().y + gravity * dt);
	setPosition(getPosition().x + (getVelocity().x * dt) * scale, getPosition().y + (getVelocity().y * dt) * scale);
	if (getPosition().y > window->getSize().y - getOrigin().y) {
		setPosition(getPosition().x, window->getSize().y - getOrigin().y);
		setVelocity(getVelocity().x, -0.8 * getVelocity().y);
	}
}

void Bounce::handleInput(float dt) {
	if (input->isKeyDown(sf::Keyboard::Space)){
		setVelocity(getVelocity().x , -10);
	}

	if (input->isMouseLDown()) {
		setPosition(input->getMouseX(), input->getMouseY());
		setVelocity(0, 0);
	}
}
