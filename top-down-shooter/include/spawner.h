#pragma once
#include <vector>
#include "gameManager.h"

using namespace std;

template <class T1>
class Spawner
{
public:
	Spawner(float duration = 5.f, int nbSpawn = 1);

	void start(shared_ptr<GameManager> gameManager);
	void stop(shared_ptr<GameManager> gameManager);

	vector<T1*> contents;

private:
	float m_duration;
	int m_nbSpawn;
};


template <class T1>
Spawner<T1>::Spawner(float duration, int nbSpawn)
{
	m_duration = duration;
	m_nbSpawn = nbSpawn;
}

template <class T1>
void Spawner<T1>::start(shared_ptr<GameManager> gameManager)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < m_nbSpawn; i++)
	{
		contents.push_back(new T1((rand() % static_cast<int>(gameManager->windowWidth)), (rand() % static_cast<int>(gameManager->windowHeight))));
	}
}