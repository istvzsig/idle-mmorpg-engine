#pragma once

#include <memory>
#include <string>

namespace IdleMMORPG
{

	class Enemy;
	class DataManager;

	class EnemyFactory
	{

	public:
		static std::unique_ptr<Enemy> create(
			const std::string &id,
			DataManager &data);
	};

}