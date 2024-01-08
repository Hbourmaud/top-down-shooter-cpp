#pragma once
#include <SFML/Graphics.hpp>
#include "gameManager.h"

using namespace std;
using namespace sf;

class Player
{
public:
	Player(float mX, float mY);
	CircleShape shape;
	float playerRadius{ 10.f }, playerVelocity{ 3.f };
	Vector2f velocity;

	void update(GameManager gameManager);

	float x();
	float y();
	float left();
	float right();
	float top();
	float bottom();

private:
};