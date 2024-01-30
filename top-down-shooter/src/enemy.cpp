#include "enemy.h"

Enemy::Enemy(float mX, float mY) : Character(mX, mY)
{
	srand((unsigned)time(NULL));
	shape.setFillColor(Color::Yellow);
	characterVelocity = { 2.f };
}

void Enemy::update(shared_ptr<GameManager> gameManager)
{
	move(gameManager);

	Character::update(gameManager);
}

void Enemy::move(shared_ptr<GameManager> gameManager)
{
	// random value with large range making more non movement
	switch (rand() % 150)
	{
	case 0:
		if (left() > 100)
		{
			velocity.x = -characterVelocity;
			velocity.y = 0;
		}
		break;
	case 1:
		if (right() < gameManager->windowWidth-100)
		{
			velocity.x = characterVelocity;
			velocity.y = 0;
		}
		break;
	case 2:
		if (top() > 100)
		{
			velocity.y = -characterVelocity;
			velocity.x = 0;
		}
		break;
	case 3:
		if (bottom() < gameManager->windowHeight-100)
		{
			velocity.y = characterVelocity;
			velocity.x = 0;
		}
		break;
	}

}