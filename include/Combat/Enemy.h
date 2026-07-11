#pragma once

#include <string>

namespace IdleMMORPG
{

	class Enemy
	{

	public:
		Enemy(
			const std::string &id,
			const std::string &name,
			int health,
			int damage,
			int experience,
			int gold,
			const std::string &loot);

		const std::string &getId() const;

		const std::string &getName() const;

		int getHealth() const;

		int getDamage() const;

		int getExperienceReward() const;

		int getGoldReward() const;

		const std::string &getLootId() const;

		void takeDamage(
			int amount);

		bool isDead() const;

	private:
		std::string m_id;

		std::string m_name;

		int m_health;

		int m_damage;

		int m_experience;

		int m_gold;

		std::string m_loot;
	};

}