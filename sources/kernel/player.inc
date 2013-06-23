/*
	
	About: player
	Author: ziggi
	
*/

#if defined _kplayer_included
	#endinput
#endif

#define _kplayer_included
#pragma library kplayer


enum info_Player {
	Float:Armour,
	Float:Health,
	IP[MAX_IP],
	Money,
	BankMoney,
	WeaponID[MAX_WEAPON_SLOT],
	WeaponAmmo[MAX_WEAPON_SLOT],
	Float:OldPos[3],
}
new gPlayer[MAX_PLAYERS][info_Player];

stock Float:player_GetMaxSpeed(playerid)
{
	// todo: add checks with animations
	return 50.0;
}

stock Float:player_GetSpeed(playerid)
{
	new Float:pos[3];
	GetPlayerVelocity(playerid, pos[0], pos[1], pos[2]);
	return floatsqroot(pos[0] * pos[0] + pos[1] * pos[1] + pos[2] * pos[2]) * 100.0;
}

stock player_SetPos(playerid, Float:x, Float:y, Float:z)
{
	gPlayer[playerid][OldPos][0] = x;
	gPlayer[playerid][OldPos][1] = y;
	gPlayer[playerid][OldPos][2] = z;
	SetPlayerPos(playerid, x, y, z);
	return 1;
}
