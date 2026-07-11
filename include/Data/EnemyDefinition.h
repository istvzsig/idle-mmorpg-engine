#pragma once

#include <string>

namespace IdleMMORPG
{

	struct EnemyDefinition
	{
		std::string id;
		std::string name;

		int health;
		int damage;

		int experience;
		int gold;

		std::string loot;
	};

}