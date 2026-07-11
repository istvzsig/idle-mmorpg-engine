#pragma once

#include <string>

namespace IdleMMORPG
{

	class Logger
	{

	public:
		enum class Level
		{
			Info,
			Warning,
			Error
		};

		static void log(
			Level level,
			const std::string &message);

		static void info(
			const std::string &message);

		static void warning(
			const std::string &message);

		static void error(
			const std::string &message);
	};

}