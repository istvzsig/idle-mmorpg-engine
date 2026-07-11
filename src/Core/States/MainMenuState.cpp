#include "Core/States/MainMenuState.h"

#include <iostream>

namespace IdleMMORPG
{

	void MainMenuState::enter()
	{
		std::cout
			<< "\n====================\n"
			<< "   Idle MMORPG\n"
			<< "====================\n"
			<< "\n"
			<< "1. Create Character\n"
			<< "2. Load Game\n"
			<< "3. Exit\n";
	}

	void MainMenuState::update()
	{
	}

	void MainMenuState::render()
	{
	}

}