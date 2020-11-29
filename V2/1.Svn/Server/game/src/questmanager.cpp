//Find
		else if (!name.compare(0,5,"xmas_"))
		{
			xmas::ProcessEventFlag(name, prev_value, value);
		}
		
///Add
#if defined(__BL_WEATHER_INFO__)
		else if (!name.compare("snow_texture")) {
			const char* mode = value ? "enable" : "disable";
			const DESC_MANAGER::DESC_SET& c_ref_set = DESC_MANAGER::instance().GetClientSet();
			for (DESC_MANAGER::DESC_SET::const_iterator it = c_ref_set.begin(); it != c_ref_set.end(); ++it) {
				LPCHARACTER ch = (*it)->GetCharacter();
				if (ch)
					ch->ChatPacket(CHAT_TYPE_COMMAND, "SnowTexture %s", mode);
			}
		}
#endif

//Find
		if ((iEventFlagValue = quest::CQuestManager::instance().GetEventFlag("newyear_boom")))
		{
			ch->ChatPacket(CHAT_TYPE_COMMAND, "newyear_boom %d", iEventFlagValue);
		}
		
///Add
#if defined(__BL_WEATHER_INFO__)
		if (quest::CQuestManager::instance().GetEventFlag("snow_texture"))
			ch->ChatPacket(CHAT_TYPE_COMMAND, "SnowTexture enable");
#endif