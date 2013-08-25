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

stock Kernel_OnPlayerConnect(playerid)
{
	KPlayer_OnConnect(playerid);
}

stock Kernel_OnPlayerDisconnect(playerid, reason)
{
	
}

stock Kernel_OnPlayerSpawn(playerid)
{
	KPlayer_OnSpawn(playerid);
}

stock Kernel_OnRequestClass(playerid, classid)
{
	KPlayer_OnRequestClass(playerid, classid);
}

stock Kernel_OnPlayerRequestSpawn(playerid)
{
	
}
