#pragma once

#include <chrono>
#include <thread>
#include <iostream>

class Timer
{
	protected:
		uint64_t m_StartTick;

	public:
		Timer();
		uint64_t GetTick();
		void Delay(uint64_t);
};