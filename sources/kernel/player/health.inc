/*

	About: health functions
	Author: ziggi

*/

#if defined _player_health_included
	#endinput
#endif

#define _player_health_included
#pragma library player_health


stock Player_SetHealth(playerid, Float:health)
{
	gPlayer[playerid][Health] = health;
	SetPlayerHealth(playerid, health);
}

stock Float:Player_GetHealth(playerid)
{
	return gPlayer[playerid][Health];
}

stock Player_GiveHealth(playerid, Float:health)
{
	Player_SetHealth(playerid, Player_GetHealth(playerid) + health);
}
