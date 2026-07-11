#pragma once

#include <string>

namespace IdleMMORPG
{

	struct ClassDefinition
	{
		std::string id;

		std::string name;

		std::string primaryStat;

		int health = 0;
		int mana = 0;
		int damage = 0;
		int armor = 0;
	};

}