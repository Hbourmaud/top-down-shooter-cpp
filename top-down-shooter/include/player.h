#pragma once
#include <vector>
#include "bullet.h"
#include "character.h"

class Player : public Character
{
public:
	Player(float mX, float mY);
	float nextShootTime{ 0.f };
	vector<Bullet> bullets;

	void update(shared_ptr<GameManager> gameManager);

private:
	void shoot(shared_ptr<GameManager> gameManager);
};