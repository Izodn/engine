#pragma once

#include <unordered_map>
#include <tuple>

#include "../core/Timer.hpp"

typedef std::string duration_key_t;
typedef std::tuple<uint64_t, uint64_t> duration_t;
typedef std::unordered_map<duration_key_t, duration_t> duration_map_t;

class Profiler
{
	// Singleton
	public:
		static Profiler* Instance();

	// Members
	private:
		duration_map_t m_DurationMap;
		Timer* m_Timer;

	// Private constructor to prevent instantiation
	private:
		Profiler();

	// Methods
	public:
		Profiler* Start(duration_key_t);
		Profiler* Stop(duration_key_t);
		Profiler* Reset();
		void Output();

	// Operators
	private:
		operator std::string() const;
};