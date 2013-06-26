/*
	
	About: kernel functions
	Author: ziggi
	
*/

#if defined _kernel_included
	#endinput
#endif

#define _kernel_included
#pragma library kernel


stock kernel_OnGameModeInit()
{
	lang_OnGameModeInit();
	log_OnGameModeInit();
	weather_OnGameModeInit();
	game_OnGameModeInit();
	return 1;
}
