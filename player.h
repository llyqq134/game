#ifndef PLAYER
#define PLAYER
#include "header.h"
#include "map.h"
#include "Entity.h"

class Map;
class Entity;

class Player : protected Entity {
private:	
	enum stateObject {left, right, stay, jump};
	stateObject state;
	bool isNextLvl;
public:
	Player(std::string file, float x, float y, float width1, float height1, float width2, float height2, std::string name);

	bool getIsAlive() {
		return isAlive;
	}

	sf::Sprite getSprite();

	void setdy(float dy);
	float getdy();

	bool getIsOnGround();

	void Control(float &time, float& currentFrame);
	void CheckCollisionWithMap(Map& map, float dx, float dy, int level);
	void Update(Map& map, float &time, int level, float &currentFrame);

	void setSprite(int width1, int height1, int width2, int height2);

	bool getIsNextLvl();
};
#endif //PLAYER