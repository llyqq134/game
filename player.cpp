#include "player.h"

Player::Player(std::string file, float x, float y, float width1, float height1, float  width2, float height2, std::string name) 
	: Entity(file, x, y, width1, height1, width2, height2,	name) {
	state = stay;
	isNextLvl = false;
	if (name == "player")
		sprite.setTextureRect(sf::IntRect(60, 40, 184, 184));
}

sf::Sprite Player::getSprite() {
	return this->Entity::getSprite();
}

void Player::setdy(float dy) {
	this->Entity::setdy(dy);
}

float Player::getdy() {
	return this->Entity::getdy();
}

bool Player::getIsOnGround() {
	return this->Entity::getIsOnground();
}

void Player::setSprite(int width1, int height1, int width2, int height2) {
	this->Entity::setSprite(width1, height1, width2, height2);
}

bool Player::getIsNextLvl() {
	return isNextLvl;
}

void Player::Control(float &time, float &currentFrame) {
	
	if (speed == 0) {
		if (state == left) {
			this->setSprite(296, 40, 164, 184);
		}
		else
			this->setSprite(60, 40, 164, 184);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		state = left;
		speed = 0.4;
		currentFrame += 0.005 * time;

		if (currentFrame > 2)
			currentFrame -= 2;

		this->setSprite(555 + 254 * int(currentFrame), 324, 164, 184);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		state = right;
		speed = 0.4;
		currentFrame += 0.005 * time;

		if (currentFrame > 2)
			currentFrame -= 2;

		this->setSprite(555 + 254 * int(currentFrame), 24, 164, 184);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isOnGround) {
		state = jump;
		dy = -1.175;
		isOnGround = false;
	}

	if (!isOnGround) {
		if (state == left)
			this->setSprite(46, 327, 170, 184);
		else
			this->setSprite(307, 327, 170, 184);
	}
}

void Player::CheckCollisionWithMap(Map& map, float dx, float dy, int level) {
	for (int i = y / 60; i < (y + height2) / 60; ++i) {
		for (int j = x / 60; j < (x + width2) / 60; ++j) {
			if (map.getLevel(level)[i][j] == '1') {
				if (dy > 0) {
					y = i * 60 - height2;
					this->dy = 0;
					isOnGround = true;
				}
				if (dy < 0) {
					y = 60 * i + 60;
					this->dy = 0;
					isOnGround = false;
				}
				if (dx > 0) {
					x = j * 60 - width2;
					this->dx = 0;
				}
				if (dx < 0) {
					x = j * 60 + 60;
					this->dx = 0;
				}
			}

			if (map.getLevel(level)[i][j] == '3')
				isNextLvl = true;
		}
	}
}

void Player::Update(Map& map, float& time, int level, float &currentFrame) {
	Control(time, currentFrame);
	switch (state) {
	case stay: break;
	case jump: break;
	case right: dx = speed; break;
	case left: dx = -speed; break;
	}

	x += dx * time;
	CheckCollisionWithMap(map, dx, 0, level);
	y += dy * time;
	CheckCollisionWithMap(map, 0, dy, level);
	speed = 0;
	sprite.setPosition(x + width2/2, y + height2/2);
	CheckCollisionWithMap(map, dy, dx, level);
	if (health <= 0)
		isAlive = false;

	if (!isOnGround) {
		dy = dy + 0.000955 * time;
	}

	dy = dy + 0.000955 * time;
	CheckCollisionWithMap(map, 0, dy, level);
}