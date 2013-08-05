/*

	About: ip functions
	Author: ziggi

*/

#if defined _player_ip_included
	#endinput
#endif

#define _player_ip_included
#pragma library player_ip


stock Player_GetIp(playerid, ip[], maxlength = sizeof(ip))
{
	strmid(ip, gPlayer[playerid][Ip], 0, maxlength);
}

stock Player_SetIp(playerid, ip[MAX_IP])
{
	gPlayer[playerid][Ip] = ip;
}
