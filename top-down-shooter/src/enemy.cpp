#include "enemy.h"

Enemy::Enemy(float mX, float mY) : Character(mX, mY)
{
	shape.setFillColor(Color::Yellow);
}

void Enemy::update(shared_ptr<GameManager> gameManager)
{
	Character::update(gameManager);
}