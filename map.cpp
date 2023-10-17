#include "map.h"

Map::Map(std::string file) {
	this->file = file;
	image.loadFromFile(file);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}

sf::Sprite& Map::getSprite() {
	return sprite;
}

sf::String* Map::getMap() {
	return level1;
}

sf::String* Map::getLevel(int level) {
	switch(level) {
	case 1: return level1; break;
	case 2: return level2; break;
	case 3: return level3; break;
	}
}