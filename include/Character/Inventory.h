#pragma once

#include <vector>
#include <memory>

#include "Items/Item.h"

namespace IdleMMORPG
{

	class Inventory
	{
	public:
		void addItem(
			std::shared_ptr<Item> item);

		const std::vector<std::shared_ptr<Item>> &
		getItems() const;

		void print() const;

	private:
		std::vector<std::shared_ptr<Item>>
			m_items;
	};

}