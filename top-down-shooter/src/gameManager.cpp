#include "gameManager.h"

GameManager::GameManager()
{
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Top-down shooter", sf::Style::Fullscreen);
	window->setFramerateLimit(60);

	if (!font.loadFromFile(".\\src\\font\\ostrich\\ostrich-regular.ttf")) std::exit(0);
	
	infoText.setFont(font);
	infoText.setCharacterSize(36);
	infoText.setFillColor(sf::Color::Red);
}

void GameManager::end()
{
	bool isPlaying = false;
	Text endReplay;

	infoText.setString("Score: " + to_string(score));

	endReplay.setFont(font);
	endReplay.setCharacterSize(36);
	endReplay.setFillColor(sf::Color::Red);
	endReplay.setString("Press R to replay");
	endReplay.setPosition(windowWidth / 2 - endReplay.getGlobalBounds().width / 2, windowHeight / 2 - endReplay.getGlobalBounds().height / 2);

	while (!isPlaying)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) std::exit(0);

		// Restart game
		if (Keyboard::isKeyPressed(Keyboard::Key::R))
		{
			window->close();
			isPlaying = true;
		}

		window->clear(Color::Black);

		window->draw(endReplay);
		window->draw(infoText);

		window->display();
	}
}