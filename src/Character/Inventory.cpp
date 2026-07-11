#include "Character/Inventory.h"

#include "Core/Logger.h"

namespace IdleMMORPG
{

	void Inventory::addItem(
		std::shared_ptr<Item> item)
	{
		if (!item)
		{
			return;
		}

		m_items.push_back(item);
	}

	const std::vector<std::shared_ptr<Item>> &
	Inventory::getItems() const
	{
		return m_items;
	}

	void Inventory::print() const
	{
		Logger::info(
			"Inventory:");

		if (m_items.empty())
		{
			Logger::info(
				" - Empty");

			return;
		}

		for (const auto &item : m_items)
		{
			Logger::info(
				" - " +
				item->getName());
		}
	}
}