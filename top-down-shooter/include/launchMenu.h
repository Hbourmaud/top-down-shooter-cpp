#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

using namespace sf;
using namespace std;

class LaunchMenu
{
public:
	LaunchMenu();

	float windowWidth{ static_cast<float>(sf::VideoMode::getFullscreenModes()[0].width) }, windowHeight{ static_cast<float>(sf::VideoMode::getFullscreenModes()[0].height) };
	
	sf::RenderWindow* window = nullptr;

	void update();

private:
	sf::Font font;
	Text playText;
	Text quitText;
	Text titleText;

	void isTextOver(Text& text, function<void(void)> func);
	void play();
	void quit();
};