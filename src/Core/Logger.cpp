#include <iostream>

#include "Core/Logger.h"

namespace IdleMMORPG
{

	void Logger::log(
		Level level,
		const std::string &message)
	{

		switch (level)
		{

		case Level::Info:

			std::cout
				<< "[INFO] "
				<< message
				<< std::endl;

			break;

		case Level::Warning:

			std::cout
				<< "[WARNING] "
				<< message
				<< std::endl;

			break;

		case Level::Error:

			std::cout
				<< "[ERROR] "
				<< message
				<< std::endl;

			break;
		}
	}

	void Logger::info(
		const std::string &message)
	{
		log(
			Level::Info,
			message);
	}

	void Logger::warning(
		const std::string &message)
	{
		log(
			Level::Warning,
			message);
	}

	void Logger::error(
		const std::string &message)
	{
		log(
			Level::Error,
			message);
	}

}