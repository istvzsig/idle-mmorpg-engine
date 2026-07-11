#pragma once

#include <string>

#include "Character/Stats.h"
#include "Character/Inventory.h"

#include "Items/Item.h"

namespace IdleMMORPG
{

	class Character
	{

	public:
		Character(
			const std::string &name,
			const std::string &race,
			const std::string &classId);

		virtual ~Character() = default;

		Stats &getStats();
		Inventory &getInventory();

		const std::string &getName() const;
		const std::string &getRace() const;
		const std::string &getClass() const;
		const Stats &getStats() const;

		int getHealth() const;
		int getLevel() const;
		int getBaseDamage() const;
		int getDamage() const;
		int getBaseArmor() const;
		int getArmor() const;

		void takeDamage(
			int amount);

		void gainExperience(
			int amount);

		void levelUp();

		void addGold(
			int amount);

		const std::shared_ptr<Item> &getEquippedWeapon() const;

		const std::shared_ptr<Item> &getEquippedArmor() const;

		void equipItem(
			std::shared_ptr<Item> item);

	protected:
		std::string m_name;
		std::string m_race;
		std::string m_class;
		Stats m_stats;
		Inventory m_inventory;
		std::shared_ptr<Item> m_weapon;
		std::shared_ptr<Item> m_armor;
	};

}