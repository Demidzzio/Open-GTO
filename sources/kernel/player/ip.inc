/*

	About: ip functions
	Author: ziggi

*/

#if defined _player_ip_included
	#endinput
#endif

#define _player_ip_included
#pragma library player_ip


stock player_GetIP(playerid, ip[], maxlength = sizeof(ip))
{
	strmid(ip, gPlayer[playerid][IP], 0, maxlength);
}

stock player_SetIP(playerid, ip[MAX_IP])
{
	gPlayer[playerid][IP] = ip;
}
