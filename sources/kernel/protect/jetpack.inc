/*
	
	About: jetpack protect
	Author: ziggi
	
*/

#if defined _jetpack_included
	#endinput
#endif

#define _jetpack_included
#pragma library jetpack


new bool:protect_jetpack_enabled = PROTECT_JETPACK_ENABLED;

stock Jetpack_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "protect_jetpack_enabled", protect_jetpack_enabled);
}

stock Jetpack_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "protect_jetpack_enabled", protect_jetpack_enabled);
}

stock Jetpack_Check(playerid)
{
	if (!protect_jetpack_enabled) {
		return 0;
	}
	if (Player_GetSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK) {
		Player_Kick(playerid, _(JETPACK_USING));
	}
	return 1;
}
