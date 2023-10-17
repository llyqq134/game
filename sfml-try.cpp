#include "player.h"
#include "map.h"
#include "Entity.h"
#include "header.h"

int startGame(sf::RenderWindow& window ,int &numberLevel, int &currentHP) {
	Player player("spr.png", 100, 833, 60, 39, 164, 187, "player");
	Enemy enemy("enemyss.png", 800, 903, 39, 165, 116, 117, "enemy");
	Map map("try2.png");
	sf::Clock clock;

	float speed = 0;
	float a = 0.2;
	float currentFrame = 0;

	while (window.isOpen()) {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}


		player.Update(map, time, numberLevel, currentFrame);
		enemy.Update(map, time, numberLevel);

		window.clear();
		sf::String* tileMap = map.getLevel(numberLevel);
		for (int i = 0; i < HEIGHT_MAP; ++i) {
			for (int j = 0; j < WIDTH_MAP; ++j) {
				if (tileMap[i][j] == '1')
					map.getSprite().setTextureRect(sf::IntRect(120, 0, 60, 60));
				if (tileMap[i][j] == '0' || j == 0)
					map.getSprite().setTextureRect(sf::IntRect(60, 0, 60, 60));
				if (tileMap[i][j] == '3')
					map.getSprite().setTextureRect(sf::IntRect(0, 0, 60, 60));
				map.getSprite().setPosition(j * 60, i * 60);

				window.draw(map.getSprite());
			}
		}

		if (player.getSprite().getGlobalBounds().intersects(enemy.getSprite().getGlobalBounds())) {
			if (player.getdy() > 0 && !player.getIsOnGround()) {
				enemy.setdx(0);
				enemy.setHealth(0);
				player.setdy(-0.2);
			}
			else {
				currentHP--;
				return 1;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) return 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) return 0;
		if (player.getIsNextLvl()) return 3;

		if (enemy.getHealth() != 0)
			window.draw(enemy.getSprite());
		else
			enemy.setSprite(0, 0, 0, 0);

		if (numberLevel == 1) {
			sf::Font font;
			font.loadFromFile("FRM325x8.ttf");
			sf::Text text("", font, 34);
			text.setColor(sf::Color(0, 0, 0));
			text.setString("a - left, d - right, space - jump");
			text.setPosition(600, 300);
			window.draw(text);
		}

		window.draw(player.getSprite());
		window.display();
	}
}

void gameRunning(sf::RenderWindow &window, int &numberLevel, int &currentHP) {
	if (currentHP == 0) {
		exit(1);
	}

	int result = startGame(window, numberLevel, currentHP);

	if (numberLevel == 3 && result == 3) {
		exit(1);
	}

	if (result == 1)
		gameRunning(window, numberLevel, currentHP);
	else if (result == 0)
		exit(0);
	else
		gameRunning(window, ++numberLevel, currentHP = 3);
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "window", sf::Style::Fullscreen);
	int level = 1;
	int currentHP = 3;
	gameRunning(window, level, currentHP);

	return 0;
}