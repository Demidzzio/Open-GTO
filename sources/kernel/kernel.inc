/*
	
	About: kernel functions
	Author: ziggi
	
*/

#if defined _kernel_included
	#endinput
#endif

#define _kernel_included
#pragma library kernel


stock Kernel_OnGameModeInit()
{
	Lang_OnGameModeInit();
	Weather_OnGameModeInit();
	Game_OnGameModeInit();
	return 1;
}
