#include "Combat/EnemyFactory.h"

#include "Combat/Enemy.h"
#include "Core/DataManager.h"
#include "Core/Logger.h"

namespace IdleMMORPG
{

	std::unique_ptr<Enemy>
	EnemyFactory::create(
		const std::string &id,
		DataManager &data)
	{
		const EnemyDefinition *definition =
			data.getEnemy(id);

		if (!definition)
		{
			Logger::error(
				"Unknown enemy: " + id);

			return nullptr;
		}

		auto enemy =
			std::make_unique<Enemy>(
				definition->id,
				definition->name,
				definition->health,
				definition->damage,
				definition->experience,
				definition->gold,
				definition->loot);

		Logger::info(
			"Created enemy: " +
			definition->name);

		return enemy;
	}

}