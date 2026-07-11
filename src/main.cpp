#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Core/Game.h"
#include "Core/Version.h"

int main()
{
	std::srand(std::time(nullptr));

	std::cout
		<< "================================\n"
		<< "        IdleMMORPG\n"
		<< "================================\n"
		<< "\n"
		<< "Version: "
		<< IdleMMORPG_VERSION_MAJOR
		<< "."
		<< IdleMMORPG_VERSION_MINOR
		<< "."
		<< IdleMMORPG_VERSION_PATCH
		<< "\n\n";

	IdleMMORPG::Game game;

	if (!game.initialize())
	{
		return 1;
	}

	game.run();

	return 0;
}