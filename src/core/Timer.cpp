#include "Timer.hpp"

// Singleton
Timer* Timer::Instance()
{
	static Timer* m_Instance = new Timer();
	return m_Instance;
}

// Constructor
Timer::Timer()
{
	m_StartMTick = std::chrono::duration_cast<std::chrono::microseconds>(
		std::chrono::system_clock::now().time_since_epoch()
	).count();
	m_StartMSTick = m_StartMTick / 1000;
}

// Methods
uint64_t Timer::GetMicroTick()
{
	return std::chrono::duration_cast<std::chrono::microseconds>(
		std::chrono::system_clock::now().time_since_epoch()
	).count() - m_StartMTick;
}
uint64_t Timer::GetTick()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
	).count() - m_StartMSTick;
}
void Timer::Delay(uint64_t milliseconds)
{
	std::this_thread::sleep_for(
		std::chrono::milliseconds(milliseconds)
	);
}