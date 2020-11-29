//Find
		if (!(thecore_heart->pulse % (thecore_heart->passes_per_sec * 3600)))
		{
			CMoneyLog::instance().Save();
		}
		
///Add
#if defined(__BL_WEATHER_INFO__)
		static bool OnSetup = true;
		if (!(thecore_heart->pulse % (thecore_heart->passes_per_sec * 60 * 20)) || OnSetup)
		{
			UpdateWeatherInfo();
			OnSetup = false;
		}
#endif