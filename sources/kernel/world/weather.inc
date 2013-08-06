/*
	
	About: random weather changer
	Author: ziggi
	
*/

#if defined _weather_included
	#endinput
#endif

#define _weather_included
#pragma library weather


#define Weather_Set		SetWeather

static weather_update_time = WEATHER_UPDATE_TIME;

stock Weather_OnGameModeInit()
{
	// todo: set default weather
	Log_Game(_(WEATHER_INIT));
}

stock Weather_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "weather_update_time", weather_update_time);
}

stock Weather_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "weather_update_time", weather_update_time);
}

stock Weather_Update()
{
	if (weather_update_time == 0) {
		return 0;
	}
	
	static timer_ticks;
	timer_ticks++;
	
	if (timer_ticks >= weather_update_time) {
		timer_ticks = 0;
		
		new weatherid = (random(2) == 0) ? mathrandom(0, 7) : mathrandom(9, 18);
		
		Weather_Set(weatherid);
		
		Log_Game(_(WEATHER_CHANGED), weatherid);
	}
	return 1;
}
