#include "Core/GameMessage.h"

#include <iostream>

namespace IdleMMORPG
{

	std::vector<std::string>
		GameMessage::m_messages;

	void GameMessage::add(
		const std::string &message)
	{
		m_messages.push_back(
			message);
	}

	void GameMessage::print()
	{
		if (m_messages.empty())
		{
			return;
		}

		std::cout
			<< "\n================================\n"
			<< "        Combat Log\n"
			<< "================================\n\n";

		for (const auto &message : m_messages)
		{
			std::cout
				<< message
				<< "\n";
		}

		std::cout
			<< "\n================================\n";

		m_messages.clear();
	}

}