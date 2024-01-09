#include "bullet.h"

Bullet::Bullet(float mX, float mY, float mouseAngle)
{
    velocity = { bulletVelocity * cos(mouseAngle) , bulletVelocity * sin(mouseAngle) };
    shape.setPosition(mX, mY);
    shape.setRadius(bulletRadius);
    shape.setFillColor(Color::Green);
    shape.setOrigin(bulletRadius, bulletRadius);
}

void Bullet::update(GameManager gameManager)
{
    shape.move(velocity);
}

float Bullet::x() { return shape.getPosition().x; }
float Bullet::y() { return shape.getPosition().y; }
float Bullet::left() { return x() - shape.getRadius(); }
float Bullet::right() { return x() + shape.getRadius(); }
float Bullet::top() { return y() - shape.getRadius(); }
float Bullet::bottom() { return y() + shape.getRadius(); }