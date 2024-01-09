#include "enemy.h"

Enemy::Enemy(float mX, float mY)
{
	shape.setPosition(mX, mY);
	shape.setRadius(enemyRadius);
	shape.setFillColor(Color::Yellow);
}

float Enemy::x() { return shape.getPosition().x; }
float Enemy::y() { return shape.getPosition().y; }
float Enemy::left() { return x() - shape.getRadius(); }
float Enemy::right() { return x() + shape.getRadius(); }
float Enemy::top() { return y() - shape.getRadius(); }
float Enemy::bottom() { return y() + shape.getRadius(); }