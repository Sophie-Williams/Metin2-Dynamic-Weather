//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#if defined(__BL_WEATHER_INFO__)
	PyModule_AddIntConstant(poModule, "__BL_WEATHER_INFO__", true);
#else
	PyModule_AddIntConstant(poModule, "__BL_WEATHER_INFO__", false);
#endif