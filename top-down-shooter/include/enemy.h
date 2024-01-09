#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Enemy
{
public:
	Enemy(float mX, float mY);
	float life{ 10.f }, enemyVelocity{ 0.5f }, enemyRadius{ 10.f };
	CircleShape shape;
	Vector2f velocity;

	float x();
	float y();
	float left();
	float right();
	float top();
	float bottom();

private:

};