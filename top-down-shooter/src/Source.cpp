#include <SFML/Graphics.hpp>
#include "player.h"
#include "gameManager.h"
#include "enemy.h"
#include "spawner.h"
#include "launchMenu.h"

using namespace std;

int startGame()
{
	shared_ptr<GameManager> gameManager{ new GameManager() };

	if (!gameManager->window)
	{
		return 1;
	}

	// make position of player in screen range

	Player player{ gameManager->windowWidth / 2, gameManager->windowHeight - 50 };

	Spawner<Enemy> spawnerEnemy{ gameManager, 7.f, 3 };

	// spawning enemy each X times
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
			(*enemy)->update(gameManager);

			++enemy;
		}

		for (auto i = player.bullets.begin(); i != player.bullets.end();)
		{
			// remove bullet after certain times for avoid too much items stay
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
			if (gameManager->isIntersecting(**enemy, player))
			{
				--player.life;
				if (player.life <= 0.f)
				{
					gameManager->end();
					startGame();
				}
			}

			for (auto bulletIt = player.bullets.begin(); bulletIt != player.bullets.end();)
			{
				if (gameManager->isIntersecting((**enemy), *bulletIt))
				{
					(*enemy)->life -= bulletIt->damage;

					if ((*enemy)->life <= 0.f)
					{
						gameManager->score += (*enemy)->scoreValue;
						enemy = spawnerEnemy.contents.erase(enemy);
					}

					bulletIt = player.bullets.erase(bulletIt);

					break;
				}

				++bulletIt;
			}

			if (enemy != spawnerEnemy.contents.end())
			{
				++enemy;
			}
		}

		gameManager->infoText.setString("Score: " + to_string(gameManager->score) + "\n HP: "+ to_string(int(player.life)));
		gameManager->window->draw(gameManager->infoText);

		gameManager->window->display();
	}
	return 0;
}

int main() {
	LaunchMenu launchMenu{};

	while (launchMenu.window->isOpen())
	{
		launchMenu.window->clear(Color::Black);

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) std::exit(0);

		launchMenu.update();

		launchMenu.window->display();
	}

	return startGame();
}