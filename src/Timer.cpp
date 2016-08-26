#include "inc/Timer.hpp"

Timer::Timer() : m_StartTick(0)
{

}

uint64_t Timer::GetTick()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
	).count() - m_StartTick;
}

void Timer::Delay(uint64_t milliseconds)
{
	std::this_thread::sleep_for(
		std::chrono::milliseconds(milliseconds)
	);
}