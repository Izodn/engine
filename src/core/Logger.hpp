#pragma once

#include <iostream>

class Logger
{
	public:
		static Logger* Self()
		{
			static Logger* instance = new Logger();
			return instance;
		};

		template<typename T>
		Logger &operator<<(const T &msg)
		{
			std::cout << msg;
			return *Self();
		}
};