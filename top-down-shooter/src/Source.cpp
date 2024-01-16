#include <SFML/Graphics.hpp>
#include "player.h"
#include "gameManager.h"
#include "enemy.h"
#include "spawner.h"

using namespace std;

int main() {
	shared_ptr<GameManager> gameManager{ new GameManager() };

	if (!gameManager->window)
	{
		return 1;
	}

	Player player{ gameManager->windowWidth / 2, gameManager->windowHeight - 50 };

	Spawner<Enemy> spawnerEnemy{};

	spawnerEnemy.start(gameManager);

	Enemy enemy = *spawnerEnemy.contents[0];

	while (gameManager->window->isOpen())
	{
		gameManager->window->clear(Color::Black);

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;

		player.update(gameManager);

		gameManager->window->draw(player.shape);

		for (auto i = spawnerEnemy.contents.begin(); i != spawnerEnemy.contents.end();)
		{
			gameManager->window->draw((*i)->shape);
			++i;
		}

		for (auto i = player.bullets.begin(); i != player.bullets.end();)
		{
			if ((*i).durationTolive <= gameManager->clock.getElapsedTime().asMilliseconds())
			{
				i = player.bullets.erase(i);

				continue;
			}

			(*i).update(gameManager);

			if (gameManager->isIntersecting(enemy, *i))
			{
				enemy.life -= i->damage;
				i = player.bullets.erase(i);

				continue;
			}

			gameManager->window->draw((*i).shape);

			++i;
		}

		gameManager->window->display();
	}
	return 0;
}