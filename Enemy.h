#ifndef ENEMY
#define ENEMY
#include "header.h"
#include "map.h"
#include "Entity.h"

class Map;
class Entity;

class Enemy : protected Entity {
public:
	Enemy(std::string file, float x, float y, int width1, int height1, int width2, int height2, std::string name);
	
	void CheckCollisionWithMap(Map& map, float dX, float dY, int level);
	void Update(Map& map, float &time, int level);

	sf::Sprite getSprite();

	void setdx(float dx);
	float getdx();

	void setHealth(int health);
	int getHealth();

	void setSprite(int width1, int height1, int width2, int height2);
};

#endif