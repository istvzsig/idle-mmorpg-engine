#include "Items/Item.h"

namespace IdleMMORPG
{

	Item::Item(
		const std::string &id,
		const std::string &name,
		const std::string &type,
		int damage,
		int armor,
		int value,
		const std::string &rarity)
		: m_id(id),
		  m_name(name),
		  m_type(type),
		  m_damage(damage),
		  m_armor(armor),
		  m_value(value),
		  m_rarity(rarity)
	{
	}

	const std::string &
	Item::getId() const
	{
		return m_id;
	}

	const std::string &
	Item::getName() const
	{
		return m_name;
	}

	const std::string &
	Item::getType() const
	{
		return m_type;
	}

	int Item::getDamage() const
	{
		return m_damage;
	}

	int Item::getArmor() const
	{
		return m_armor;
	}

	int Item::getValue() const
	{
		return m_value;
	}

	const std::string &
	Item::getRarity() const
	{
		return m_rarity;
	}

}