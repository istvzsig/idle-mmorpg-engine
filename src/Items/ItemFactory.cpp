#include "Items/ItemFactory.h"

#include "Items/Item.h"
#include "Core/DataManager.h"
#include "Core/Logger.h"

namespace IdleMMORPG
{

	std::shared_ptr<Item>
	ItemFactory::create(
		const std::string &id,
		DataManager &data)
	{
		const ItemDefinition *definition =
			data.getItem(id);

		if (!definition)
		{
			Logger::error(
				"Unknown item: " + id);

			return nullptr;
		}

		auto item =
			std::make_shared<Item>(
				definition->id,
				definition->name,
				definition->type,
				definition->damage,
				definition->armor,
				definition->value,
				definition->rarity);

		return item;
	}

}