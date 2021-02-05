///Add
#if defined(__BL_WEATHER_INFO__)
#include <unordered_map>
#include "PythonBackground.h"
#endif

//Find
	else if (!strcmpi(szCmd, "gift"))
	{
		PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "Gift_Show", Py_BuildValue("()")); 	
	}
	
///Add
#if defined(__BL_WEATHER_INFO__)
	else if (!strcmpi(szCmd, "SnowTexture"))
	{
		if (2 != TokenVector.size()) {
			TraceError("CPythonNetworkStream::ServerCommand(c_szCommand=%s) - Strange Parameter Count", c_szCommand);
			return;
		}
		
		if (!CPythonBackground::Instance().IsMapOutdoor())
			return;
		
		static const std::unordered_map<std::string, std::pair<std::string, std::string>> TextureList = {
			{ "metin2_map_a1", { "textureset/metin2_a1.txt", "textureset/snow/snow_metin2_a1.txt" }},
			{ "map_a2",	{ "textureset/metin2_a2.txt", "textureset/snow/snow_metin2_a2.txt" }},
			{ "metin2_map_a3", { "textureset/metin2_a3.txt", "textureset/snow/snow_metin2_a3.txt" }},
			{ "metin2_map_b1", { "textureset/metin2_b1.txt", "textureset/snow/snow_metin2_b1.txt" }},
			{ "metin2_map_b3", { "textureset/metin2_b3.txt", "textureset/snow/snow_metin2_b3.txt" }},
			{ "metin2_map_c1", { "textureset/metin2_c1.txt", "textureset/snow/snow_metin2_c1.txt" }},
			{ "metin2_map_c3", { "textureset/metin2_c3.txt", "textureset/snow/snow_metin2_c3.txt" }},
			{ "metin2_map_milgyo", { "textureset/metin2_milgyo.txt", "textureset/snow/snow_metin2_milgyo.txt" }},
			{ "metin2_map_n_flame_01", { "textureset/metin2_n_flame_01.txt", "textureset/snow/snow_metin2_n_flame_01.txt" }},
			{ "metin2_map_n_desert_01", { "textureset/metin2_n_desert1.txt", "textureset/snow/snow_metin2_n_desert_01.txt" }},
			{ "season1/metin2_map_oxevent", { "textureset/metin2_map_oxevent.txt", "textureset/snow/snow_metin2_map_oxevent.txt" }},
		};
		
		auto it = TextureList.find(CPythonBackground::Instance().GetWarpMapName());
		if (it == TextureList.end())
			return;

		enum { NORMAL, SNOW };

		if (!TokenVector.at(1).compare("enable"))
			CPythonBackground::Instance().GetMapOutdoorRef().ChangeTextureset(std::get<SNOW>(it->second));
		else
			CPythonBackground::Instance().GetMapOutdoorRef().ChangeTextureset(std::get<NORMAL>(it->second));
	}
#endif