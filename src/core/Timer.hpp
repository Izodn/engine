#pragma once

#include <chrono>
#include <thread>

class Timer
{
	// Singleton
	public:
		static Timer* Instance();

	// Members
	protected:
		uint64_t m_StartMTick;
		uint64_t m_StartMSTick;

	// Private constructor to prevent instantiation
	private:
		Timer();

	// Methods
	public:
		uint64_t GetMicroTick();
		uint64_t GetTick();
		void Delay(uint64_t);
};