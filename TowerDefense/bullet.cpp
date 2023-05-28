#include "bullet.h"

Bullet::Bullet(int posX, int posY, sf::Texture& texture)
{
	this->setPosition(posX, posY);
	this->setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
	this->setTexture(texture);
}

void Bullet::setHitStatus(bool hitInfo)
{
	this->hit = hitInfo;
}

bool Bullet::getHitStatus()
{
	return this->hit;
}