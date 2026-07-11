#include <string>

#include "Core/Game.h"
#include "Core/DataManager.h"
#include "Core/Logger.h"
#include "Core/GameMessage.h"

#include "Character/CharacterFactory.h"

#include "Combat/Enemy.h"
#include "Combat/EnemyFactory.h"
#include "Combat/CombatSystem.h"
#include "Combat/CombatResult.h"

#include "Items/ItemFactory.h"

namespace IdleMMORPG
{

	Game::Game()
		: m_running(false)
	{
	}

	Game::~Game()
	{
	}

	bool Game::initialize()
	{
		Logger::info(
			"Initializing game engine");

		if (!m_dataManager.loadAll())
		{
			Logger::error(
				"Failed loading game data");

			return false;
		}

		std::string name =
			m_ui.createCharacterName();

		std::string raceId =
			m_ui.chooseCharacterRace(
				m_dataManager);

		std::string classId =
			m_ui.chooseCharacterClass(
				m_dataManager);

		m_player =
			CharacterFactory::create(
				name,
				raceId,
				classId,
				m_dataManager);

		if (!m_player)
		{
			Logger::error(
				"Failed creating character");

			return false;
		}

		Logger::info(
			"Created character: " + m_player->getName());

		Logger::info(
			"Level: " +
			std::to_string(
				m_player->getLevel()));

		Logger::info(
			"Health: " +
			std::to_string(
				m_player->getStats().health));

		Logger::info(
			"Mana: " +
			std::to_string(
				m_player->getStats().mana));

		Logger::info(
			"Damage: " +
			std::to_string(
				m_player->getDamage()));

		Logger::info(
			"Armor: " +
			std::to_string(
				m_player->getArmor()));

		m_currentEnemy =
			m_enemySpawner.spawn(
				m_dataManager);

		if (!m_currentEnemy)
		{
			Logger::error(
				"Failed creating starting enemy");

			return false;
		}

		m_running = true;

		return true;
	}

	void Game::run()
	{
		if (!m_running)
		{
			return;
		}

		while (m_running)
		{
			render();

			char input =
				m_ui.getInput();

			switch (input)
			{
			case 'f':
			case 'F':
				update();
				break;

			case 'i':
			case 'I':

				m_ui.showInventory(*this);

				m_ui.waitForInput();

				break;

			case 'c':
			case 'C':

				m_ui.showCharacter(*this);

				m_ui.waitForInput();

				break;

			case 'q':
			case 'Q':

				shutdown();

				break;

			default:

				Logger::error(
					"Unknown command");

				break;
			}
		}

		shutdown();
	}

	void Game::update()
	{

		Logger::info(
			"Updating game");

		if (!m_currentEnemy)
		{
			return;
		}

		CombatResult result =
			m_combat.fight(
				*m_player,
				*m_currentEnemy);

		GameMessage::add(
			"You hit for " +
			std::to_string(result.damageDealt) +
			" damage.");

		GameMessage::add(
			"You take " +
			std::to_string(result.damageTaken) +
			" damage.");

		if (m_currentEnemy->isDead())
		{
			GameMessage::add(
				m_currentEnemy->getName() +
				" defeated!");

			int xp =
				m_currentEnemy->getExperienceReward();

			int gold =
				m_currentEnemy->getGoldReward();

			int oldLevel =
				m_player->getLevel();

			m_player->gainExperience(xp);

			if (m_player->getLevel() > oldLevel)
			{
				GameMessage::add(
					"LEVEL UP!");
			}

			m_player->addGold(
				gold);

			const auto lootId =
				m_currentEnemy->getLootId();

			GameMessage::add(
				"XP gained: " +
				std::to_string(xp));

			GameMessage::add(
				"Gold gained: " +
				std::to_string(gold));

			if (!lootId.empty())
			{
				Logger::info(
					"Attempting loot: " + lootId);

				auto item =
					ItemFactory::create(
						lootId,
						m_dataManager);

				if (!item)
				{
					Logger::error(
						"Failed creating loot item");

					return;
				}

				GameMessage::add(
					"Loot received: " +
					item->getName());

				std::shared_ptr<Item> sharedItem =
					std::move(item);

				Logger::info(
					"Adding item to inventory");

				m_player->getInventory()
					.addItem(sharedItem);

				Logger::info(
					"Item added");

				m_player
					->equipItem(sharedItem);
			}

			Logger::info(
				"Level: " +
				std::to_string(
					m_player->getStats().level));

			Logger::info(
				"XP: " +
				std::to_string(
					m_player->getStats().experience) +
				"/" +
				std::to_string(
					m_player->getStats().experienceRequired));

			Logger::info(
				"Total Gold: " +
				std::to_string(
					m_player->getStats().gold));

			m_ui.showInventory(*this);

			Logger::info(
				"Combat finished");

			m_currentEnemy =
				m_enemySpawner.spawn(
					m_dataManager);
		}
	}

	void Game::render()
	{
		m_ui.draw(*this);
		GameMessage::print();
	}

	void Game::shutdown()
	{
		if (!m_running)
		{
			return;
		}

		Logger::info(
			"Shutting down engine");

		m_running = false;
	}

	const std::unique_ptr<Character> &
	Game::getPlayer() const
	{
		return m_player;
	}

	const std::unique_ptr<Enemy> &
	Game::getCurrentEnemy() const
	{
		return m_currentEnemy;
	}

}