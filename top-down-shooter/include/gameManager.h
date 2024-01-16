#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class GameManager
{
public:
	GameManager();

	float windowWidth{ static_cast<float>(sf::VideoMode::getFullscreenModes()[0].width)}, windowHeight{static_cast<float>(sf::VideoMode::getFullscreenModes()[0].height)};

	sf::RenderWindow* window = nullptr;
	sf::Clock clock;

	template <class T1, class T2>
	bool isIntersecting(T1& mA, T2& mB)
	{
		return mA.shape.getGlobalBounds().intersects(mB.shape.getGlobalBounds());
	};

private:

};