#include "character.h"

Character::Character(float mX, float mY)
{
	shape.setPosition(mX, mY);
	shape.setRadius(characterRadius);
	shape.setOrigin(characterRadius, characterRadius);
}

void Character::update(shared_ptr<GameManager> gameManager)
{
	shape.move(velocity);
}

float Character::x() { return shape.getPosition().x; }
float Character::y() { return shape.getPosition().y; }
float Character::left() { return x() - shape.getRadius(); }
float Character::right() { return x() + shape.getRadius(); }
float Character::top() { return y() - shape.getRadius(); }
float Character::bottom() { return y() + shape.getRadius(); }