#include "launchMenu.h"

LaunchMenu::LaunchMenu()
{
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Top-down shooter", sf::Style::Fullscreen);

	if (!font.loadFromFile(".\\src\\font\\ostrich\\ostrich-regular.ttf")) std::exit(0);

	titleText.setFont(font);
	titleText.setCharacterSize(72);
	titleText.setFillColor(sf::Color::Green);
	titleText.setString("Round Rampage");
	titleText.setPosition(windowWidth / 2 - titleText.getGlobalBounds().width / 2, windowHeight / 3 - 50);

	subtitleText.setFont(font);
	subtitleText.setCharacterSize(30);
	subtitleText.setFillColor(sf::Color::Red);
	subtitleText.setString("Ultimate Edition");
	subtitleText.setPosition(windowWidth / 2 + 100, windowHeight / 3 + 50);
	subtitleText.setRotation(340);

	playText.setFont(font);
	quitText.setFont(font);
	playText.setCharacterSize(36);
	quitText.setCharacterSize(36);
	playText.setFillColor(sf::Color::White);
	quitText.setFillColor(sf::Color::White);
	playText.setString("Play");
	quitText.setString("Quit");
	playText.setPosition(windowWidth / 2 - playText.getGlobalBounds().width / 2, windowHeight / 2 - playText.getGlobalBounds().height / 2 - 50);
	quitText.setPosition(windowWidth / 2 - quitText.getGlobalBounds().width / 2, windowHeight / 2 - quitText.getGlobalBounds().height / 2 + 50);
}

void LaunchMenu::update()
{

	isTextOver(playText, std::bind(&LaunchMenu::play, this));
	isTextOver(quitText, std::bind(&LaunchMenu::quit, this));

	window->draw(titleText);
	window->draw(subtitleText);
	window->draw(playText);
	window->draw(quitText);
}

void LaunchMenu::isTextOver(Text& text, function<void(void)> func)
{
	if (Mouse::getPosition(*window).x >= text.getGlobalBounds().left && Mouse::getPosition(*window).x <= text.getGlobalBounds().left + text.getGlobalBounds().width
		&& Mouse::getPosition(*window).y >= text.getGlobalBounds().top && Mouse::getPosition(*window).y <= text.getGlobalBounds().top + text.getGlobalBounds().height)
	{
		text.setFillColor(sf::Color::Yellow);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			func();
		}

		return;
	}

	text.setFillColor(sf::Color::White);
}

void LaunchMenu::quit()
{
	std::exit(0);
}

void LaunchMenu::play()
{
	window->close();
}