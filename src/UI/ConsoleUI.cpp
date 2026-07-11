#include <iostream>

#include "UI/ConsoleUI.h"

#include "Core/Game.h"

#include "Character/Character.h"

#include "Combat/Enemy.h"

namespace IdleMMORPG
{

	void ConsoleUI::draw(
		const Game &game) const
	{
		std::cout
			<< "\n================================\n"
			<< "        Idle MMORPG Engine\n"
			<< "================================\n\n";

		const auto &player =
			game.getPlayer();

		if (player)
		{

			std::cout
				<< "Name:  " << player->getName() << "\n"
				<< "Race:  " << player->getRace() << "\n"
				<< "Class:  " << player->getClass() << "\n"
				<< "Level:  " << player->getLevel() << "\n"
				<< "HP:     " << player->getStats().health
				<< "/" << player->getStats().maxHealth << "\n"
				<< "Mana:   " << player->getStats().mana
				<< "/" << player->getStats().maxMana << "\n"
				<< "Damage: " << player->getDamage() << "\n"
				<< "Armor:  " << player->getArmor() << "\n"
				<< "Gold:   " << player->getStats().gold << "\n"
				<< "XP:     " << player->getStats().experience
				<< "/" << player->getStats().experienceRequired << "\n";
		}

		std::cout
			<< "\n";

		auto &enemy =
			game.getCurrentEnemy();

		if (enemy)
		{
			std::cout
				<< "Enemy:\n\n";

			std::cout
				<< enemy->getName()
				<< "\n";

			std::cout
				<< "HP: "
				<< enemy->getHealth()
				<< "\n";
		}

		std::cout
			<< "\n================================\n";
	}

	void ConsoleUI::showCharacter(
		const Game &game) const
	{
		const auto &player =
			game.getPlayer();

		std::cout
			<< "\n================================\n"
			<< "        Character\n"
			<< "================================\n\n"

			<< "Name:   "
			<< player->getName()
			<< "\n"

			<< "Race:   "
			<< player->getRace()
			<< "\n"

			<< "Class:  "
			<< player->getClass()
			<< "\n\n"

			<< "Level:  "
			<< player->getLevel()
			<< "\n"

			<< "Gold:   "
			<< player->getStats().gold
			<< "\n"

			<< "XP:     "
			<< player->getStats().experience
			<< "/"
			<< player->getStats().experienceRequired
			<< "\n\n"

			<< "Health: "
			<< player->getStats().health
			<< "/"
			<< player->getStats().maxHealth
			<< "\n"

			<< "Mana:   "
			<< player->getStats().mana
			<< "/"
			<< player->getStats().maxMana
			<< "\n\n"

			<< "Damage: "
			<< player->getDamage()
			<< "\n"

			<< "Armor:  "
			<< player->getArmor()
			<< "\n\n"

			<< "Equipment\n"
			<< "--------------------------------\n";

		if (player->getEquippedWeapon())
		{
			std::cout
				<< "Weapon : "
				<< player->getEquippedWeapon()->getName()
				<< "\n";
		}
		else
		{
			std::cout
				<< "Weapon : None\n";
		}

		if (player->getEquippedArmor())
		{
			std::cout
				<< "Armor  : "
				<< player->getEquippedArmor()->getName()
				<< "\n";
		}
		else
		{
			std::cout
				<< "Armor  : None\n";
		}
	}

	void ConsoleUI::showInventory(
		const Game &game) const
	{
		std::cout
			<< "\n================================\n"
			<< "        Inventory\n"
			<< "================================\n\n";

		game.getPlayer()
			->getInventory()
			.print();
	}

	char ConsoleUI::getInput() const
	{
		std::cout
			<< "\nActions:\n\n"
			<< "[F] Fight\n"
			<< "[I] Inventory\n"
			<< "[C] Character\n"
			<< "[Q] Quit\n\n"
			<< "> ";

		char input;

		std::cin >> input;

		return input;
	}

	void ConsoleUI::waitForInput() const
	{
		std::cout
			<< "\nPress ENTER to continue...";

		std::cin.ignore(
			std::numeric_limits<std::streamsize>::max(),
			'\n');

		std::cin.get();
	}

	std::string ConsoleUI::createCharacterName() const
	{
		std::string name;

		std::cout
			<< "\n================================\n"
			<< "     Character Creation\n"
			<< "================================\n\n"
			<< "Enter name: ";

		std::cin >> name;

		return name;
	}

	std::string ConsoleUI::chooseCharacterRace(
		const DataManager &data) const
	{
		std::vector<std::string> ids;

		std::cout
			<< "\n================================\n"
			<< "     Choose Race\n"
			<< "================================\n\n";

		int index = 1;

		for (const auto &id : data.getRaceIds())
		{
			const auto *race =
				data.getRace(id);

			std::cout
				<< index
				<< ". "
				<< race->name
				<< "\n";

			ids.push_back(id);

			index++;
		}

		int choice;

		std::cout
			<< "\n> ";

		std::cin >> choice;

		if (choice < 1 ||
			choice > static_cast<int>(ids.size()))
		{
			return ids[0];
		}

		return ids[choice - 1];
	}

	std::string ConsoleUI::chooseCharacterClass(
		const DataManager &data) const
	{
		std::cout
			<< "\nChoose class:\n\n";

		int index = 1;

		std::vector<std::string> ids;

		for (const auto &id : data.getClassIds())
		{
			const auto *classDef =
				data.getClass(id);

			std::cout
				<< index
				<< ". "
				<< classDef->name
				<< "\n";

			ids.push_back(id);

			index++;
		}

		std::cout << "\n> ";

		int choice;
		std::cin >> choice;

		if (choice < 1 ||
			choice > static_cast<int>(ids.size()))
		{
			return ids[0];
		}

		return ids[choice - 1];
	}

}