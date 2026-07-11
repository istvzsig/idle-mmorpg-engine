#pragma once

#include <memory>
#include <string>
#include <vector>

namespace IdleMMORPG
{

	class Enemy;
	class DataManager;

	class EnemySpawner
	{

	public:
		std::unique_ptr<Enemy> spawn(
			DataManager &data);

	private:
		std::vector<std::string> m_enemyIds =
			{
				"forest_rat",
				"wild_goblin"};
	};

}