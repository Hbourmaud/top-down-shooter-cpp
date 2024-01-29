#include "gameManager.h"

GameManager::GameManager()
{
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Top-down shooter", sf::Style::Fullscreen);
	window->setFramerateLimit(60);

	scoreText.setCharacterSize(36);
	scoreText.setFillColor(sf::Color::Red);
}