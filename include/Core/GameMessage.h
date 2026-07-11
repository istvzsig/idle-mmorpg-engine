#pragma once

#include <string>
#include <vector>

namespace IdleMMORPG
{

	class GameMessage
	{
	public:
		static void add(
			const std::string &message);

		static void print();

	private:
		static std::vector<std::string> m_messages;
	};

}