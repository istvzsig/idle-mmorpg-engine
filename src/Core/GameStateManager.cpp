#include "Core/GameStateManager.h"

namespace IdleMMORPG
{

	void GameStateManager::changeState(
		std::unique_ptr<GameState> state)
	{

		if (currentState)
		{
			currentState->exit();
		}

		currentState = std::move(state);

		if (currentState)
		{
			currentState->enter();
		}
	}

	void GameStateManager::update()
	{
		if (currentState)
		{
			currentState->update();
		}
	}

	void GameStateManager::render()
	{
		if (currentState)
		{
			currentState->render();
		}
	}

}