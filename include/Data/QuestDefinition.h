#pragma once

#include <string>

namespace IdleMMORPG
{

	struct QuestDefinition
	{
		std::string id;

		std::string name;

		std::string description;

		std::string enemyId;

		int amount = 0;

		int xpReward = 0;

		int goldReward = 0;
	};

}