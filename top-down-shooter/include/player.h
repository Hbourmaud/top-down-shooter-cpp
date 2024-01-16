#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "gameManager.h"
#include "bullet.h"

using namespace std;
using namespace sf;

class Player
{
public:
	Player(float mX, float mY);
	CircleShape shape;
	float playerRadius{ 10.f }, playerVelocity{ 0.75f }, life{ 10.f }, nextShootTime{ 0.f };
	Vector2f velocity;
	vector<Bullet> bullets;

	void update(shared_ptr<GameManager> gameManager);

	float x();
	float y();
	float left();
	float right();
	float top();
	float bottom();

private:
	void shoot(shared_ptr<GameManager> gameManager);
};