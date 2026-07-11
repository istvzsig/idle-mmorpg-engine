#include "Combat/Enemy.h"

namespace IdleMMORPG
{

	Enemy::Enemy(
		const std::string &id,
		const std::string &name,
		int health,
		int damage,
		int experience,
		int gold,
		const std::string &loot)
		: m_id(id),
		  m_name(name),
		  m_health(health),
		  m_damage(damage),
		  m_experience(experience),
		  m_gold(gold),
		  m_loot(loot)
	{
	}

	const std::string &
	Enemy::getId() const
	{
		return m_id;
	}

	const std::string &
	Enemy::getName() const
	{
		return m_name;
	}

	int Enemy::getHealth() const
	{
		return m_health;
	}

	int Enemy::getDamage() const
	{
		return m_damage;
	}

	int Enemy::getExperienceReward() const
	{
		return m_experience;
	}

	int Enemy::getGoldReward() const
	{
		return m_gold;
	}

	const std::string &
	Enemy::getLootId() const
	{
		return m_loot;
	}

	void Enemy::takeDamage(
		int amount)
	{
		m_health -= amount;

		if (m_health < 0)
		{
			m_health = 0;
		}
	}

	bool Enemy::isDead() const
	{
		return m_health <= 0;
	}

}