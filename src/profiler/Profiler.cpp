#include "Profiler.hpp"

#include <sstream>

#include "../core/Logger.hpp"

// Singleton
Profiler* Profiler::Instance()
{
	static Profiler* m_Instance = new Profiler();
	return m_Instance;
}

// Constructor
Profiler::Profiler()
{
	m_Timer = Timer::Instance();
}

// Methods
Profiler* Profiler::Start(duration_key_t key)
{
	#ifdef PROFILER
		m_DurationMap[key] = std::make_tuple(m_Timer->GetMicroTick(), 0);
	#endif
	return this;
}
Profiler* Profiler::Stop(duration_key_t key)
{
	#ifdef PROFILER
		std::get<1>(m_DurationMap[key]) = m_Timer->GetMicroTick();
	#endif
	return this;
}
Profiler* Profiler::Reset()
{
	#ifdef PROFILER
		m_DurationMap.clear();
	#endif
	return this;
}
void Profiler::Output()
{
	#ifdef PROFILER
		Logger() << (std::string)*this << "\n";
	#endif
}

// Operators
Profiler::operator std::string() const
{
	#ifdef PROFILER
		std::string retStr = "Profiler: {\n";

		for (auto it = m_DurationMap.begin(); it != m_DurationMap.end(); it++) {
			std::ostringstream strDuration;
			strDuration << std::get<1>(it->second) - std::get<0>(it->second);

			retStr += "\t" + it->first + ": ";
			if (std::get<1>(it->second) == 0) {
				retStr += "did not profile";
			} else {
				retStr += strDuration.str();
				retStr += "micro seconds";
			}
			retStr += ",\n";
		}

		retStr += "}";

		return retStr;
	#else
		return "";
	#endif
}