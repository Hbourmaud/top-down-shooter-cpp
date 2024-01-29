#pragma once
#include "character.h"

class Enemy : public Character
{
public:
	Enemy(float mX, float mY);
	int scoreValue{ 5 };

	void update(shared_ptr<GameManager> gameManager);

private:
	void move(shared_ptr<GameManager> gameManager);
};