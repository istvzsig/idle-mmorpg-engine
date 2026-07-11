#pragma once

#include <memory>

#include "Core/GameState.h"

// Controls which part of the game is active.
namespace IdleMMORPG
{

	class GameStateManager
	{

	public:
		void changeState(
			std::unique_ptr<GameState> state);

		void update();

		void render();

	private:
		std::unique_ptr<GameState> currentState;
	};

}