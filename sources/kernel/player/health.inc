/*

	About: health functions
	Author: ziggi

*/

#if defined _player_health_included
	#endinput
#endif

#define _player_health_included
#pragma library player_health


stock player_SetHealth(playerid, Float:health)
{
	gPlayer[playerid][Health] = health;
	SetPlayerHealth(playerid, health);
}

stock Float:player_GetHealth(playerid)
{
	return gPlayer[playerid][Health];
}

stock player_GiveHealth(playerid, Float:health)
{
	player_SetHealth(playerid, player_GetHealth(playerid) + health);
}
