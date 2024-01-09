#include "player.h"

Player::Player(float mX, float mY)
{
    shape.setPosition(mX, mY);
    shape.setRadius(playerRadius);
    shape.setFillColor(Color::Red);
    shape.setOrigin(playerRadius, playerRadius);
}

void Player::update(GameManager gameManager)
{
    shape.move(velocity);

    if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0)
    {
        velocity.x = -playerVelocity;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Key::Right) &&
        right() < gameManager.windowWidth)
    {
        velocity.x = playerVelocity;
    }
    else
    {
        velocity.x = 0;
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::Up) && top() > 0)
    {
        velocity.y = -playerVelocity;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Key::Down) &&
        bottom() < gameManager.windowHeight)
    {
        velocity.y = playerVelocity;
    }
    else
    {
        velocity.y = 0;
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::Space))
    {
        if (nextShootTime <= gameManager.clock.getElapsedTime().asMilliseconds())
        {
            shoot(gameManager);
            nextShootTime = gameManager.clock.getElapsedTime().asMilliseconds() + 1000;
        }
    }
}

void Player::shoot(GameManager gameManager)
{
    Bullet bullet{ x(), y() };
    bullet.durationTolive = gameManager.clock.getElapsedTime().asMilliseconds() + 3000;
    bullets.push_back(bullet);
}

float Player::x() { return shape.getPosition().x; }
float Player::y() { return shape.getPosition().y; }
float Player::left() { return x() - shape.getRadius(); }
float Player::right() { return x() + shape.getRadius(); }
float Player::top() { return y() - shape.getRadius(); }
float Player::bottom() { return y() + shape.getRadius(); }