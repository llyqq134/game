#include "Enemy.h"

Enemy::Enemy(std::string file, float x, float y, int width1, int height1, int width2, int height2, std::string name)
	: Entity(file, x, y, width1, height1, width2, height2, name) {
	if (name == "enemy")
		sprite.setTextureRect(sf::IntRect(width1, height1, width2, height2));
	dx = -0.1;
}

void Enemy::CheckCollisionWithMap(Map &map, float dx, float dy, int level) {
	for (int i = y / 60; i < (y + height2) / 60; ++i) {
		for (int j = x / 60; j < (x + width2) / 60; ++j) {
			if (map.getLevel(level)[i][j] == '1') {
				if (dy > 0) 
					y = i * 60 - 60;
				if (dy < 0) {
					y = i * 60 + 60;
				}
				if (dx > 0) {
					x = j * 60 - width2;
					this->dx = -0.1;
					sprite.scale(-1, 1);
				}
				if (dx < 0) {
					x = j * 60 + 60;
					this->dx = 0.1;
					sprite.scale(-1, 1);
				}
			}
		}
	}
}

void Enemy::Update(Map &map, float &time, int level) {
	CheckCollisionWithMap(map, dx, 0, level);
	x += dx * time;
	sprite.setPosition(x + width2 / 2, y + height2 / 2);
	if (health <= 0)
		isAlive = false;
}

sf::Sprite Enemy::getSprite() {
	return this->Entity::getSprite();
}

void Enemy::setdx(float dx) {
	this->Entity::setdx(dx);
}

float Enemy::getdx() {
	return this->getdx();
}

void Enemy::setHealth(int health) {
	this->Entity::setHealth(health);
}

int Enemy::getHealth() {
	return this->Entity::getHealth();
}

void Enemy::setSprite(int width1, int height1, int width2, int height2) {
	this->Entity::setSprite(width1, height1, width2, height2);
}