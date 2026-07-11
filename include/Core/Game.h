#pragma once

#include <memory>

#include "Core/GameStateManager.h"
#include "Core/DataManager.h"

#include "Combat/Enemy.h"
#include "Combat/EnemySpawner.h"
#include "Combat/CombatSystem.h"

#include "UI/ConsoleUI.h"

#include "Character/Character.h"

namespace IdleMMORPG
{

	class Game
	{
	public:
		Game();
		~Game();

		bool initialize();

		void run();

		void update();

		void render();

		void shutdown();

		const std::unique_ptr<Character> &
		getPlayer() const;

		const std::unique_ptr<Enemy> &
		getCurrentEnemy() const;

	private:
		bool m_running;

		DataManager m_dataManager;
		GameStateManager m_stateManager;

		CombatSystem m_combat;

		std::unique_ptr<Character> m_player;

		std::unique_ptr<Enemy> m_currentEnemy;

		EnemySpawner m_enemySpawner;

		ConsoleUI m_ui;
	};

}
