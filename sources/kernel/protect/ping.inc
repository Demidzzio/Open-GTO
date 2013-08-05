/*

	About: ping protect
	Author: ziggi

*/

#if defined _ping_included
	#endinput
#endif

#define _ping_included
#pragma library ping


new bool:protect_ping_enabled = PROTECT_PING_ENABLED,
	protect_ping_maxping = PROTECT_PING_MAX_PING;

stock Ping_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "protect_ping_enabled", protect_ping_enabled);
	ini_getInteger(file_cfg, "protect_ping_maxping", protect_ping_maxping);
}

stock Ping_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "protect_ping_enabled", protect_ping_enabled);
	ini_setInteger(file_cfg, "protect_ping_maxping", protect_ping_maxping);
}

stock Ping_Check(playerid)
{
	if (!protect_ping_enabled) {
		return 0;
	}
	if (Player_GetPing(playerid) > protect_ping_maxping) {
		new string[MAX_STRING];
		format(string, sizeof(string), _(PROTECT_PING_KICK), protect_ping_maxping);
		Player_Kick(playerid, string);
	}
	return 1;
}
