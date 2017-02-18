#pragma once

#include <chrono>
#include <thread>

class Timer
{
	protected:
		uint64_t m_StartMTick;
		uint64_t m_StartMSTick;

	public:
		Timer();
		uint64_t GetMicroTick();
		uint64_t GetTick();
		void Delay(uint64_t);
};