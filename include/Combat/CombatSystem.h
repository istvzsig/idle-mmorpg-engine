#pragma once

#include "Character/Character.h"
#include "Combat/Enemy.h"
#include "Combat/CombatResult.h"

namespace IdleMMORPG
{

	class CombatSystem
	{

	public:
		CombatResult fight(
			Character &player,
			Enemy &enemy);
	};

}