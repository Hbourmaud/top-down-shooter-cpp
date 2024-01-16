#pragma once
#include <SFML/Graphics.hpp>
#include "gameManager.h"

class Bullet
{
public:
	Bullet(float mX, float mY, float mouseAngle);
	CircleShape shape;
	float damage{ 5.f }, bulletRadius{ 5.f }, bulletVelocity{ 5.f }, durationTolive{ 0.f };
	Vector2f velocity;

	void update(shared_ptr<GameManager> gameManager);

	float x();
	float y();
	float left();
	float right();
	float top();
	float bottom();

private:

};
