/*

	About: ping protect
	Author: ziggi

*/

#if defined _ping_included
	#endinput
#endif

#define _ping_included
#pragma library ping


stock Ping_Check(playerid)
{
	if (!gProtectConf[c_Ping]) {
		return 0;
	}
	if (Player_GetPing(playerid) > gProtectConf[c_PingMax]) {
		new string[MAX_STRING];
		format(string, sizeof(string), _(PROTECT_PING_KICK), gProtectConf[c_PingMax]);
		Player_Kick(playerid, string);
	}
	return 1;
}
