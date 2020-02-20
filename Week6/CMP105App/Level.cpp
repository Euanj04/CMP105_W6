#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	boingTexture.loadFromFile("gfx/Beach_Ball.png");
	directionTexture.loadFromFile("gfx/goomba.png");

	boing.setWindow(window);
	boing.setInput(input);
	boing.setTexture(&boingTexture);
	boing.setPosition(500, 100);
	boing.setSize(sf::Vector2f(100, 100));
	boing.setOrigin(boing.getSize().x / 2,boing.getSize().y / 2);

	directions.setInput(input);
	directions.setTexture(&directionTexture);
	directions.setPosition(0, 0);
	directions.setSize(sf::Vector2f(100, 100));
	directions.setOrigin(directions.getSize().x / 2, directions.getSize().y / 2);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	boing.handleInput(dt);

	directions.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	boing.update(dt);

	directions.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(boing);

	window->draw(directions);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}