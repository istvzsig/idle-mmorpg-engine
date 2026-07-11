#pragma once

// Every game screen inherits from this.
// Menu, character creation, combat, world exploration become states.
namespace IdleMMORPG
{

	class GameState
	{

	public:
		virtual ~GameState() = default;

		virtual void enter()
		{
		}

		virtual void update()
		{
		}

		virtual void render()
		{
		}

		virtual void exit()
		{
		}
	};

}