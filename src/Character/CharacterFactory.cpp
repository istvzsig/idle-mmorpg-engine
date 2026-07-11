#include "Character/CharacterFactory.h"

#include "Character/Character.h"

#include "Core/Logger.h"
#include "Core/DataManager.h"
#include "Items/ItemFactory.h"

namespace IdleMMORPG
{

	std::unique_ptr<Character>
	CharacterFactory::create(
		const std::string &name,
		const std::string &raceId,
		const std::string &classId,
		DataManager &data)
	{

		auto characterClass =
			data.getClass(classId);

		if (!characterClass)
		{
			Logger::error(
				"Unknown class: " + classId);

			return nullptr;
		}

		auto character =
			std::make_unique<Character>(
				name,
				raceId,
				classId);

		auto weapon =
			ItemFactory::create(
				"rusty_sword",
				data);

		if (weapon)
		{
			std::shared_ptr<Item> sharedWeapon =
				std::move(weapon);

			character->getInventory()
				.addItem(
					sharedWeapon);

			character->equipItem(
				sharedWeapon);
		}

		auto armor =
			ItemFactory::create(
				"leather_armor",
				data);

		if (armor)
		{
			std::shared_ptr<Item> sharedArmor =
				std::move(armor);

			character->getInventory()
				.addItem(
					sharedArmor);

			character->equipItem(
				sharedArmor);
		}

		return character;
	}

}