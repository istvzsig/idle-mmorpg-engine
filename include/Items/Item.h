#pragma once

#include <string>

namespace IdleMMORPG
{

	class Item
	{
	public:
		Item(
			const std::string &id,
			const std::string &name,
			const std::string &type,
			int damage,
			int armor,
			int value,
			const std::string &rarity);

		virtual ~Item() = default;

		const std::string &getId() const;
		const std::string &getName() const;
		const std::string &getType() const;
		const std::string &getRarity() const;

		int getDamage() const;
		int getArmor() const;
		int getValue() const;

	private:
		std::string m_id;
		std::string m_name;
		std::string m_type;

		int m_damage;
		int m_armor;
		int m_value;

		std::string m_rarity;
	};

}