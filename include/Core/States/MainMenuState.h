#pragma once

#include "Core/GameState.h"

namespace IdleMMORPG
{

	class MainMenuState : public GameState
	{

	public:
		void enter() override;

		void update() override;

		void render() override;
	};

}