#include "libIncludes.h"

class Bullet : public sf::Sprite
{
private:
	bool hit = false;
public:
	Bullet(int posX, int posY, sf::Texture& texture);
	void setHitStatus(bool hitInfo);
	bool getHitStatus();
};