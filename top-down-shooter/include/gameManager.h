#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class GameManager
{
public:
	GameManager();

	float windowWidth{ 800 }, windowHeight{ 600 };

	sf::RenderWindow* window = nullptr;
	sf::Clock clock;

	template <class T1, class T2>
	bool isIntersecting(T1& mA, T2& mB)
	{
		return mA.right() >= mB.left() && mA.left() <= mB.right() &&
			mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
	};

private:

};