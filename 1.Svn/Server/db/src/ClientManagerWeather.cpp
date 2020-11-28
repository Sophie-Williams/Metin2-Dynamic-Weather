#include "stdafx.h"
#include "ClientManager.h"

enum DayMode : BYTE { DAY, NIGHT };

static BYTE GetDayMode(int Hour)
{ 
	if (Hour >= 6 && Hour <= 20)
		return DayMode::DAY;
	return DayMode::NIGHT;
}

static bool IsWinter(int Month)
{
	return (Month < 3);
}

void CClientManager::UpdateWeatherInfo()
{
	time_t CurrentTime = time(nullptr);
	tm* tm = localtime(&CurrentTime);

	auto SendFlag = [&](const char* flag, BYTE val) {
		TEventFlagMap::const_iterator it = m_map_lEventFlag.find(flag);
		if ((it != m_map_lEventFlag.end() && it->second == val) == false) {
			TPacketSetEventFlag p;
			std::strcpy(p.szFlagName, flag);
			p.lValue = val;
			CClientManager::Instance().SetEventFlag(&p);
		}
	};
	
	SendFlag("eclipse", GetDayMode(tm->tm_hour));
	bool Winter = IsWinter(tm->tm_mon);
	for (const auto& Flag : { "xmas_snow", "xmas_tree" })
		SendFlag(Flag, Winter);
}