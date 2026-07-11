#include <fstream>

#include "Core/DataManager.h"
#include "Core/Logger.h"

namespace IdleMMORPG
{

	bool DataManager::loadFile(
		const std::string &path,
		nlohmann::json &destination)
	{
		std::ifstream file(path);

		if (!file.is_open())
		{
			Logger::error(
				"Cannot load data file: " + path);

			return false;
		}

		try
		{
			file >> destination;
		}
		catch (const std::exception &error)
		{
			Logger::error(
				"Invalid JSON in " +
				path +
				": " +
				error.what());

			return false;
		}

		Logger::info(
			"Loaded data: " + path);

		return true;
	}

	bool DataManager::loadAll()
	{
		bool result = true;

		result &= loadFile(
			"data/classes.json",
			m_classes);

		result &= loadFile(
			"data/races.json",
			m_races);

		result &= loadFile(
			"data/enemies.json",
			m_enemies);

		result &= loadFile(
			"data/items.json",
			m_items);

		result &= loadFile(
			"data/quests.json",
			m_quests);

		if (!result)
		{
			return false;
		}

		loadClassDefinitions();

		loadRaceDefinitions();

		loadEnemyDefinitions();

		loadItemDefinitions();

		loadQuestDefinitions();

		return true;
	}

	const std::unordered_map<std::string, RaceDefinition> &
	DataManager::getRaces() const
	{
		return m_raceDefinitions;
	}

	const std::vector<std::string> &
	DataManager::getRaceIds() const
	{
		return m_raceIds;
	}

	const RaceDefinition *
	DataManager::getRace(
		const std::string &id) const
	{
		auto iterator =
			m_raceDefinitions.find(id);

		if (iterator == m_raceDefinitions.end())
		{
			return nullptr;
		}

		return &iterator->second;
	}

	const std::unordered_map<std::string, ClassDefinition> &
	DataManager::getClasses() const
	{
		return m_classDefinitions;
	}

	const std::vector<std::string> &
	DataManager::getClassIds() const
	{
		return m_classIds;
	}

	const ClassDefinition *
	DataManager::getClass(
		const std::string &id) const
	{
		auto iterator =
			m_classDefinitions.find(id);

		if (iterator == m_classDefinitions.end())
		{
			return nullptr;
		}

		return &iterator->second;
	}

	const std::vector<std::string> &
	DataManager::getEnemyIds() const
	{
		return m_enemyIds;
	}

	const EnemyDefinition *
	DataManager::getEnemy(
		const std::string &id) const
	{
		auto iterator =
			m_enemyDefinitions.find(id);

		if (iterator == m_enemyDefinitions.end())
		{
			return nullptr;
		}

		return &iterator->second;
	}

	const ItemDefinition *
	DataManager::getItem(
		const std::string &id) const
	{
		auto iterator =
			m_itemDefinitions.find(id);

		if (iterator == m_itemDefinitions.end())
		{
			return nullptr;
		}

		return &iterator->second;
	}

	const QuestDefinition *
	DataManager::getQuest(
		const std::string &id) const
	{
		auto iterator =
			m_questDefinitions.find(id);

		if (iterator == m_questDefinitions.end())
		{
			return nullptr;
		}

		return &iterator->second;
	}

	void DataManager::loadRaceDefinitions()
	{
		m_raceDefinitions.clear();
		m_raceIds.clear();

		for (const auto &entry : m_races)
		{
			RaceDefinition race;

			race.id =
				entry["id"];

			m_raceIds.push_back(
				race.id);

			race.name =
				entry["name"];

			race.bonus =
				entry["bonus"];

			m_raceDefinitions[race.id] =
				race;

			Logger::info(
				"Loaded race: " +
				race.id);
		}

		Logger::info(
			"Race definitions loaded: " +
			std::to_string(
				m_raceDefinitions.size()));
	}

	void DataManager::loadClassDefinitions()
	{
		m_classDefinitions.clear();
		m_classIds.clear();

		for (const auto &entry : m_classes)
		{
			ClassDefinition definition;

			definition.id =
				entry["id"];

			m_classIds.push_back(
				definition.id);

			definition.name =
				entry["name"];

			definition.primaryStat =
				entry["primary_stat"];

			definition.health =
				entry["health"];

			definition.mana =
				entry["mana"];

			definition.damage =
				entry["damage"];

			definition.armor =
				entry["armor"];

			m_classDefinitions[definition.id] =
				definition;

			Logger::info(
				"Loaded class: " +
				definition.id);
		}

		Logger::info(
			"Class definitions loaded: " +
			std::to_string(
				m_classDefinitions.size()));
	}

	void DataManager::loadEnemyDefinitions()
	{
		m_enemyDefinitions.clear();
		m_enemyIds.clear();

		for (const auto &enemy : m_enemies)
		{
			EnemyDefinition definition;

			definition.id =
				enemy["id"];

			definition.name =
				enemy["name"];

			definition.health =
				enemy["health"];

			definition.damage =
				enemy["damage"];

			definition.experience =
				enemy["experience"];

			definition.gold =
				enemy["gold"];

			if (enemy.contains("loot"))
			{
				definition.loot =
					enemy["loot"];
			}

			m_enemyDefinitions[definition.id] =
				definition;

			Logger::info(
				"Loaded enemy: " +
				definition.id);
		}

		Logger::info(
			"Enemy definitions loaded: " +
			std::to_string(
				m_enemyDefinitions.size()));
	}

	void DataManager::loadItemDefinitions()
	{
		m_itemDefinitions.clear();

		for (const auto &itemJson : m_items)
		{
			ItemDefinition item;

			item.id =
				itemJson["id"];

			item.name =
				itemJson.value(
					"name",
					item.id);

			item.type =
				itemJson.value(
					"type",
					"misc");

			item.damage =
				itemJson.value(
					"damage",
					0);

			item.armor =
				itemJson.value(
					"armor",
					0);

			item.value =
				itemJson.value(
					"value",
					0);

			item.rarity =
				itemJson.value(
					"rarity",
					"common");

			m_itemDefinitions[item.id] =
				item;

			Logger::info(
				"Loaded item: " +
				item.id);
		}

		Logger::info(
			"Item definitions loaded: " +
			std::to_string(
				m_itemDefinitions.size()));
	}

	void DataManager::loadQuestDefinitions()
	{
		Logger::info(
			"Quest definitions loading not implemented yet");
	}

}