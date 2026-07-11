#include <string>

#include "Core/Logger.h"

#include "Character/Character.h"

namespace IdleMMORPG
{

	Character::Character(
		const std::string &name,
		const std::string &race,
		const std::string &classId)
		: m_name(name),
		  m_race(race),
		  m_class(classId)
	{
	}

	const std::string &
	Character::getName() const
	{
		return m_name;
	}

	const std::string &
	Character::getRace() const
	{
		return m_race;
	}

	const std::string &
	Character::getClass() const
	{
		return m_class;
	}

	Stats &
	Character::getStats()
	{
		return m_stats;
	}

	const Stats &
	Character::getStats() const
	{
		return m_stats;
	}

	Inventory &Character::getInventory()
	{
		return m_inventory;
	}

	int Character::getHealth() const
	{
		return m_stats.health;
	}

	int Character::getLevel() const
	{
		return m_stats.level;
	}

	void Character::takeDamage(
		int amount)
	{
		m_stats.health -= amount;

		if (m_stats.health < 0)
		{
			m_stats.health = 0;
		}
	}

	void Character::gainExperience(
		int amount)
	{
		m_stats.experience += amount;

		while (
			m_stats.experience >=
			m_stats.experienceRequired)
		{
			m_stats.experience -=
				m_stats.experienceRequired;

			levelUp();
		}
	}

	void Character::levelUp()
	{
		m_stats.level++;

		m_stats.experienceRequired =
			m_stats.level * 100;

		m_stats.maxHealth += 20;
		m_stats.health =
			m_stats.maxHealth;

		m_stats.maxMana += 10;
		m_stats.mana =
			m_stats.maxMana;

		m_stats.baseDamage += 2;
		m_stats.baseArmor += 1;

		Logger::info(
			"LEVEL UP!");

		Logger::info(
			"New level: " +
			std::to_string(
				m_stats.level));
	}

	void Character::addGold(
		int amount)
	{
		m_stats.gold += amount;
	}

	const std::shared_ptr<Item> &
	Character::getEquippedWeapon() const
	{
		return m_weapon;
	}

	const std::shared_ptr<Item> &
	Character::getEquippedArmor() const
	{
		return m_armor;
	}

	void Character::equipItem(
		std::shared_ptr<Item> item)
	{
		if (!item)
		{
			return;
		}

		if (item->getType() == "weapon")
		{
			m_weapon = item;

			Logger::info(
				"Equipped weapon: " +
				item->getName());
		}

		if (item->getType() == "armor")
		{
			m_armor = item;

			Logger::info(
				"Equipped armor: " +
				item->getName());
		}
	}

	int Character::getBaseDamage() const
	{
		return m_stats.baseDamage;
	}

	int Character::getDamage() const
	{
		int damage =
			m_stats.baseDamage;

		if (m_weapon)
		{
			damage += m_weapon->getDamage();
		}

		return damage;
	}

	int Character::getBaseArmor() const
	{
		return m_stats.baseArmor;
	}

	int Character::getArmor() const
	{
		int armor =
			m_stats.baseArmor;

		if (m_armor)
		{
			armor += m_armor->getArmor();
		}

		return armor;
	}
}