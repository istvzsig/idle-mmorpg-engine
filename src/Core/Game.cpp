#include <string>
#include <memory>

#include "Core/Logger.h"
#include "Core/Game.h"
#include "Core/GameMessage.h"
#include "Core/DataManager.h"
#include "Core/States/MainMenuState.h"

#include "Combat/Enemy.h"
#include "Combat/EnemyFactory.h"
#include "Combat/CombatSystem.h"
#include "Combat/CombatResult.h"

#include "Character/CharacterFactory.h"
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

		m_stateManager.changeState(
			std::make_unique<MainMenuState>());

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

			m_stateManager.update();

			m_stateManager.render();
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
			std::to_string(
				result.damageDealt) +
			" damage.");

		GameMessage::add(
			"You take " +
			std::to_string(
				result.damageTaken) +
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

			GameMessage::add(
				"XP gained: " +
				std::to_string(xp));

			GameMessage::add(
				"Gold gained: " +
				std::to_string(gold));

			const auto lootId =
				m_currentEnemy->getLootId();

			if (!lootId.empty())
			{

				Logger::info(
					"Attempting loot: " +
					lootId);

				auto item =
					ItemFactory::create(
						lootId,
						m_dataManager);

				if (item)
				{

					GameMessage::add(
						"Loot received: " +
						item->getName());

					std::shared_ptr<Item> sharedItem =
						std::move(item);

					m_player
						->getInventory()
						.addItem(sharedItem);

					m_player
						->equipItem(sharedItem);
				}
			}

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