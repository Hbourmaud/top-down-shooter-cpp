#pragma once
#include <SFML/Graphics.hpp>
#include "gameManager.h"

using namespace std;
using namespace sf;

class Character
{
public:
	Character(float mX, float mY);
	float characterRadius{ 10.f }, characterVelocity{ 7.5f }, life{ 10.f };
	CircleShape shape;
	Vector2f velocity;

	void update(shared_ptr<GameManager> gameManager);

	float x();
	float y();
	float left();
	float right();
	float top();
	float bottom();
};