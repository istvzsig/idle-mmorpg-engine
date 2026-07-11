#include "Combat/CombatSystem.h"

namespace IdleMMORPG
{

	CombatResult CombatSystem::fight(
		Character &player,
		Enemy &enemy)
	{
		CombatResult result;

		int damage =
			player.getDamage();

		enemy.takeDamage(
			damage);

		result.damageDealt =
			damage;

		if (enemy.isDead())
		{
			result.victory = true;

			result.experienceGained =
				enemy.getExperienceReward();

			result.goldGained =
				enemy.getGoldReward();

			return result;
		}

		int enemyDamage =
			enemy.getDamage();

		player.takeDamage(
			enemyDamage);

		result.damageTaken =
			enemyDamage;

		return result;
	}

}