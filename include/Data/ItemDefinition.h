#pragma once

#include <string>

namespace IdleMMORPG
{

	struct ItemDefinition
	{
		std::string id;
		std::string name;
		std::string type; // weapon, armor, misc
		int damage = 0;
		int armor = 0;
		int value = 0;
		std::string rarity;
	};

}