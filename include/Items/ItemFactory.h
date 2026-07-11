#pragma once

#include <memory>
#include <string>

namespace IdleMMORPG
{

	class Item;
	class DataManager;

	class ItemFactory
	{

	public:
		static std::shared_ptr<Item> create(
			const std::string &id,
			DataManager &data);
	};

}