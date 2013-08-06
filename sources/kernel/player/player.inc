/*
	
	About: player
	Author: ziggi
	
*/

#if defined _kplayer_included
	#endinput
#endif

#define _kplayer_included
#pragma library kplayer


#define Player_IsNPC		IsPlayerNPC
#define Player_AddClass		AddPlayerClass

enum Info_Player {
	Float:p_Armour,
	Float:p_Health,
	p_Name[MAX_PLAYER_NAME + 1],
	p_Ip[MAX_IP],
	p_Money,
	p_WeaponID[MAX_WEAPON_SLOT],
	p_WeaponAmmo[MAX_WEAPON_SLOT],
	p_WeaponSkill[11],
	Float:p_OldPos[3],
	p_Score,
}
new gPlayer[MAX_PLAYERS][Info_Player];

/*

	Speed

*/

stock Float:Player_GetMaxSpeed(playerid)
{
	// todo: add checks with animations
	return 50.0;
}

stock Float:Player_GetSpeed(playerid)
{
	new Float:pos[3];
	GetPlayerVelocity(playerid, pos[0], pos[1], pos[2]);
	return floatsqroot(pos[0] * pos[0] + pos[1] * pos[1] + pos[2] * pos[2]) * 100.0;
}

/*

	Position

*/

stock Player_GetOldPos(playerid, &Float:x, &Float:y, &Float:z)
{
	x = gPlayer[playerid][p_OldPos][0];
	y = gPlayer[playerid][p_OldPos][1];
	z = gPlayer[playerid][p_OldPos][2];
	return 1;
}

stock Player_SetOldPos(playerid, Float:x, Float:y, Float:z)
{
	gPlayer[playerid][p_OldPos][0] = x;
	gPlayer[playerid][p_OldPos][1] = y;
	gPlayer[playerid][p_OldPos][2] = z;
	return 1;
}

stock Player_GetPos(playerid, &Float:x, &Float:y, &Float:z)
{
	GetPlayerPos(playerid, x, y, z);
	return 1;
}

stock Player_SetPos(playerid, Float:x, Float:y, Float:z)
{
	Player_SetOldPos(playerid, x, y, z);
	SetPlayerPos(playerid, x, y, z);
	return 1;
}

/*

	Name

*/

stock Player_GetName(playerid, name[], len = sizeof(name))
{
	return GetPlayerName(playerid, name, len);
}

stock Player_SetName(playerid, name[])
{
	return SetPlayerName(playerid, name);
}


/*

	Ping

*/

stock Player_GetPing(playerid)
{
	new ping = GetPlayerPing(playerid);
	if (ping == 65535) {
		ping = 0;
	}
	return ping;
}


/*

	Score

*/

stock Player_GetScore(playerid)
{
	return gPlayer[playerid][p_Score];
}

stock Player_SetScore(playerid, score)
{
	gPlayer[playerid][p_Score] = score;
	SetPlayerScore(playerid, score);
}

stock Player_GiveScore(playerid, score)
{
	gPlayer[playerid][p_Score] += score;
	SetPlayerScore(playerid, gPlayer[playerid][p_Score]);
}

/*

	Weapon skill

*/

stock Player_GetSkillLevel(playerid, skill)
{
	return gPlayer[playerid][skill];
}

stock Player_SetSkillLevel(playerid, skill, level)
{
	gPlayer[playerid][skill] = level;
	SetPlayerSkillLevel(playerid, skill, level);
}

stock Player_GiveSkillLevel(playerid, skill)
{
	gPlayer[playerid][skill] += skill;
	SetPlayerSkillLevel(playerid, skill, gPlayer[playerid][skill]);
}
