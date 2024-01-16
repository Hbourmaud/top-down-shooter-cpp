#include "player.h"

Player::Player(float mX, float mY) : Character(mX, mY)
{
	shape.setFillColor(Color::Red);
}

void Player::update(shared_ptr <GameManager> gameManager)
{
	Character::update(gameManager);

	if (Keyboard::isKeyPressed(Keyboard::Key::Q) && left() > 0)
	{
		velocity.x = -characterVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::D) &&
		right() < gameManager->windowWidth)
	{
		velocity.x = characterVelocity;
	}
	else
	{
		velocity.x = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Z) && top() > 0)
	{
		velocity.y = -characterVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::S) &&
		bottom() < gameManager->windowHeight)
	{
		velocity.y = characterVelocity;
	}
	else
	{
		velocity.y = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Space))
	{
		if (nextShootTime <= gameManager->clock.getElapsedTime().asMilliseconds())
		{
			shoot(gameManager);
			nextShootTime = gameManager->clock.getElapsedTime().asMilliseconds() + 1000;
		}
	}
}

void Player::shoot(shared_ptr<GameManager> gameManager)
{
	float mouseAngle = atan2(Mouse::getPosition(*gameManager->window).y - shape.getPosition().y, Mouse::getPosition(*gameManager->window).x - shape.getPosition().x);

	Bullet bullet{ x(), y(), mouseAngle };
	bullet.durationTolive = gameManager->clock.getElapsedTime().asMilliseconds() + 3000;
	bullets.push_back(bullet);
}