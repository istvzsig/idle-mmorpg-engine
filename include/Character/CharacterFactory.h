#pragma once

#include <memory>
#include <string>
#include "Character.h"

namespace IdleMMORPG
{

	class Character;
	class DataManager;

	class CharacterFactory
	{

	public:
		static std::unique_ptr<Character>
		create(
			const std::string &name,
			const std::string &raceId,
			const std::string &classId,
			DataManager &data);
	};

}