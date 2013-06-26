/*

	About: armour functions
	Author: ziggi

*/

#if defined _player_armour_included
	#endinput
#endif

#define _player_armour_included
#pragma library player_armour


stock player_SetArmour(playerid, Float:armour)
{
	gPlayer[playerid][Armour] = armour;
	SetPlayerArmour(playerid, armour);
}

stock Float:player_GetArmour(playerid)
{
	return gPlayer[playerid][Armour];
}

stock player_GiveArmour(playerid, Float:armour)
{
	player_SetArmour(playerid, player_GetArmour(playerid) + armour);
}
