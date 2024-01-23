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

	Spawner<Enemy> spawnerEnemy{ gameManager, 7.f, 3 };

	spawnerEnemy.start();

	while (gameManager->window->isOpen())
	{
		gameManager->window->clear(Color::Black);

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;

		spawnerEnemy.update();

		player.update(gameManager);

		gameManager->window->draw(player.shape);

		for (auto enemy = spawnerEnemy.contents.begin(); enemy != spawnerEnemy.contents.end();)
		{
			gameManager->window->draw((*enemy)->shape);

			++enemy;
		}

		for (auto i = player.bullets.begin(); i != player.bullets.end();)
		{
			if ((*i).durationTolive <= gameManager->clock.getElapsedTime().asMilliseconds())
			{
				i = player.bullets.erase(i);

				continue;
			}

			(*i).update(gameManager);

			gameManager->window->draw((*i).shape);

			++i;
		}

		for (auto enemy = spawnerEnemy.contents.begin(); enemy != spawnerEnemy.contents.end();)
		{
			for (auto i = player.bullets.begin(); i != player.bullets.end();)
			{
				if (gameManager->isIntersecting((**enemy), *i))
				{
					(*enemy)->life -= i->damage;

					if ((*enemy)->life <= 0.f)
					{
						enemy = spawnerEnemy.contents.erase(enemy);
					}

					i = player.bullets.erase(i);

					break;
				}

				++i;
			}

			if (enemy != spawnerEnemy.contents.end())
			{
				++enemy;
			}
		}

		gameManager->window->display();
	}
	return 0;
}