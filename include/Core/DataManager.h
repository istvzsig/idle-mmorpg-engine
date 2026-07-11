#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include <nlohmann/json.hpp>

#include "Data/RaceDefinition.h"
#include "Data/ClassDefinition.h"
#include "Data/EnemyDefinition.h"
#include "Data/ItemDefinition.h"
#include "Data/QuestDefinition.h"

namespace IdleMMORPG
{

	class DataManager
	{

	public:
		bool loadAll();

		const RaceDefinition *getRace(
			const std::string &id) const;

		const std::unordered_map<std::string, RaceDefinition> &
		getRaces() const;

		const std::vector<std::string> &
		getRaceIds() const;

		const ClassDefinition *getClass(
			const std::string &id) const;

		const std::unordered_map<std::string, ClassDefinition> &
		getClasses() const;

		const std::vector<std::string> &
		getClassIds() const;

		const EnemyDefinition *getEnemy(
			const std::string &id) const;

		const std::vector<std::string> &
		getEnemyIds() const;

		const ItemDefinition *getItem(
			const std::string &id) const;

		const QuestDefinition *getQuest(
			const std::string &id) const;

	private:
		bool loadFile(
			const std::string &path,
			nlohmann::json &destination);

		void loadRaceDefinitions();

		void loadClassDefinitions();

		void loadEnemyDefinitions();

		void loadItemDefinitions();

		void loadQuestDefinitions();

	private:
		// Raw JSON data

		nlohmann::json m_races;
		nlohmann::json m_classes;
		nlohmann::json m_enemies;
		nlohmann::json m_items;
		nlohmann::json m_quests;

		std::vector<std::string> m_raceIds;
		std::vector<std::string> m_classIds;
		std::vector<std::string> m_enemyIds;

		// Runtime lookup database

		std::unordered_map<std::string, RaceDefinition>
			m_raceDefinitions;

		std::unordered_map<std::string, ClassDefinition>
			m_classDefinitions;

		std::unordered_map<std::string, EnemyDefinition>
			m_enemyDefinitions;

		std::unordered_map<std::string, ItemDefinition>
			m_itemDefinitions;

		std::unordered_map<std::string, QuestDefinition>
			m_questDefinitions;
	};

}