#include <cstdlib>
#include <ctime>

#include "Combat/EnemySpawner.h"

#include "Combat/Enemy.h"
#include "Combat/EnemyFactory.h"

#include "Core/DataManager.h"
#include "Core/Logger.h"

namespace IdleMMORPG
{

	std::unique_ptr<Enemy>
	EnemySpawner::spawn(
		DataManager &data)
	{
		if (m_enemyIds.empty())
		{
			return nullptr;
		}

		int index =
			std::rand() %
			m_enemyIds.size();

		const auto &id =
			m_enemyIds[index];

		Logger::info(
			"Spawning enemy: " + id);

		return EnemyFactory::create(
			id,
			data);
	}

}