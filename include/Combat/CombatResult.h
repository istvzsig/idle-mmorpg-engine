#pragma once

namespace IdleMMORPG
{

	struct CombatResult
	{
		bool victory = false;

		int damageDealt = 0;

		int damageTaken = 0;

		int experienceGained = 0;

		int goldGained = 0;
	};

}