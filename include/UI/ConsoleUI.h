#pragma once

#include <string>

namespace IdleMMORPG
{

	class Game;
	class DataManager;

	class ConsoleUI
	{
	public:
		void draw(
			const Game &game) const;

		char getInput() const;

		void showCharacter(
			const Game &game) const;

		void showInventory(
			const Game &game) const;

		void waitForInput() const;

		std::string createCharacterName() const;

		std::string chooseCharacterRace(
			const DataManager &data) const;

		std::string chooseCharacterClass(
			const DataManager &data) const;
	};

}