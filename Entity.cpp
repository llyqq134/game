#include "Entity.h"

Entity::Entity(std::string file, float x, float y, int width1, int height1, int width2, int height2 ,std::string name) {
	this->x = x;
	this->y = y;
	this->width1 = width1;
	this->height1 = height1;
	this->width2 = width2;
	this->height2 = height2;
	speed = 0;

	if (name == "player")
		health = 3;
	else {
		health = 1;
	}

	isOnGround = false;
	
	image.loadFromFile(file);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setOrigin(width2 / 2, height2 / 2);
}

sf::Sprite Entity::getSprite() {
	return this->sprite;
}

sf::FloatRect Entity::getRect() {
	return sf::FloatRect(x, y, width2, height2);
}

void Entity::setdx(float dx) {
	this->dx = dx;
}

float Entity::getdx() {
	return dx;
}

void Entity::setdy(float dy) {
	this->dy = dy;
}

float Entity::getdy() {
	return dy;
}

bool Entity::getIsOnground() {
	return isOnGround;
}

void Entity::setHealth(int health) {
	this->health = health;
}

int Entity::getHealth() {
	return health;
}

void Entity::setSprite(int width1, int height1, int width2, int height2) {
	this->width1 = width1;
	this->height1 = height1;
	this->width2 = width2;
	this->height2 = height2;
	sprite.setTextureRect(sf::IntRect(width1, height1, width2, height2));
}