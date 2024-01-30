#pragma once
#include <vector>
#include "gameManager.h"

using namespace std;

// Because of templating, all the code of spawner are here
// This class usefull for spawn anything in random position (enemy, items...)

template <class T1>
class Spawner
{
public:
	Spawner(shared_ptr<GameManager> gameManager, float duration = 5.f, int nbSpawn = 1);

	void start();
	void stop();
	void update();

	vector<T1*> contents;

private:
	float m_duration;
	int m_nbSpawn; // number of entity to spawn each duration reached
	float m_nextWave;
	shared_ptr<GameManager> m_gameManager;

	void spawnEnemy();
};


template <class T1>
Spawner<T1>::Spawner(shared_ptr<GameManager> gameManager, float duration, int nbSpawn)
{
	m_duration = duration;
	m_nbSpawn = nbSpawn;
	m_gameManager = gameManager;
}

template <class T1>
void Spawner<T1>::start()
{
	m_nextWave = m_gameManager->clock.getElapsedTime().asMilliseconds() + m_duration * 1000;

	srand((unsigned)time(NULL));
	spawnEnemy();
}

template <class T1>
void Spawner<T1>::update()
{
	if (m_nextWave != -1.f && m_gameManager->clock.getElapsedTime().asMilliseconds() > m_nextWave)
	{
		m_nextWave += m_duration * 1000;
		spawnEnemy();
	}
}

template <class T1>
void Spawner<T1>::spawnEnemy()
{
	for (int i = 0; i < m_nbSpawn; i++)
	{
		contents.push_back(new T1((rand() % static_cast<int>(m_gameManager->windowWidth)), (rand() % static_cast<int>(m_gameManager->windowHeight))));
	}
}

template <class T1>
void Spawner<T1>::stop()
{
	m_nextWave = -1.f;
}