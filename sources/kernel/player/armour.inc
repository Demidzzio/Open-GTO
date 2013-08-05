/*

	About: armour functions
	Author: ziggi

*/

#if defined _player_armour_included
	#endinput
#endif

#define _player_armour_included
#pragma library player_armour


stock Player_SetArmour(playerid, Float:armour)
{
	gPlayer[playerid][Armour] = armour;
	SetPlayerArmour(playerid, armour);
}

stock Float:Player_GetArmour(playerid)
{
	return gPlayer[playerid][Armour];
}

stock Player_GiveArmour(playerid, Float:armour)
{
	Player_SetArmour(playerid, Player_GetArmour(playerid) + armour);
}
