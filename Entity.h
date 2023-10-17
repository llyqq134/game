#ifndef ENTITY
#define ENTITY
#include "header.h"

class Entity {
protected:
	float dx, dy, x, y, speed;
	int width1, height1, width2, height2, health;
	bool isAlive, isOnGround;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::String name;
	Entity(std::string file, float x, float y, int width1, int height1, int width2, int height2, std::string name);
public:
	sf::Sprite getSprite();

	sf::FloatRect getRect();

	void setdy(float dy);
	float getdy();

	void setdx(float dx);
	float getdx();

	void setHealth(int health);
	int getHealth();

	void setSprite(int width1, int height1, int width2, int height2);

	bool getIsOnground();
};
#endif