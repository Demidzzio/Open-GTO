/*

	About: ping protect
	Author: ziggi

*/

#if defined _ping_included
	#endinput
#endif

#define _ping_included
#pragma library ping


new protect_ping_Enabled = PROTECT_PING_ENABLED,
	protect_ping_MaxPing = PROTECT_PING_MAX_PING;

stock ping_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "protect_ping_Enabled", protect_ping_Enabled);
	ini_getInteger(file_cfg, "protect_ping_MaxPing", protect_ping_MaxPing);
	return 1;
}

stock ping_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "protect_ping_Enabled", protect_ping_Enabled);
	ini_setInteger(file_cfg, "protect_ping_MaxPing", protect_ping_MaxPing);
	return 1;
}

stock ping_Check(playerid)
{
	if (!protect_ping_Enabled) {
		return 0;
	}
	if (GetPlayerPing(playerid) > protect_ping_MaxPing) {
		new string[MAX_STRING];
		format(string, sizeof(string), _(PROTECT_PING_KICK), protect_ping_MaxPing);
		player_Kick(playerid, string);
	}
	return 1;
}