///Add
#include "PythonBackground.h"
#include <unordered_map>

//Find
	else if (!strcmpi(szCmd, "gift"))
	{
		PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "Gift_Show", Py_BuildValue("()")); 	
	}
	
///Add
#if defined(__BL_WEATHER_INFO__)
	else if (!strcmpi(szCmd, "SnowTexture"))
	{
		if (TokenVector.size() < 2) {
			TraceError("CPythonNetworkStream::ServerCommand(c_szCommand=%s) - Strange Parameter Count.", c_szCommand);
			return;
		}

		static const std::unordered_map<std::string, std::pair<std::string, std::string>> SnowTextureset
		{
			{ "metin2_map_a1", { "textureset/metin2_a1.txt", "textureset/snow/snow_metin2_a1.txt" } },
			{ "metin2_map_b1", { "textureset/metin2_b1.txt", "textureset/snow/snow_metin2_b1.txt" } },
			{ "metin2_map_c1", { "textureset/metin2_c1.txt", "textureset/snow/snow_metin2_c1.txt" } },
		};

		const decltype(SnowTextureset)::const_iterator it = SnowTextureset.find(CPythonBackground::Instance().GetWarpMapName());
		if (it == SnowTextureset.end())
			return;

		enum TEXTURE_TYPE { NORMAL, SNOW };

		if (!TokenVector.at(1).compare("enable"))
			CPythonBackground::Instance().GetMapOutdoorRef().ChangeTextureset(std::get<TEXTURE_TYPE::SNOW>(it->second));
		else
			CPythonBackground::Instance().GetMapOutdoorRef().ChangeTextureset(std::get<TEXTURE_TYPE::NORMAL>(it->second));
	}
#endif