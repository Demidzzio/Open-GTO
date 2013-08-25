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

#define Player_ToggleSpectating		TogglePlayerSpectating
#define Player_SetCameraPos			SetPlayerCameraPos
#define Player_SetCameraLookAt		SetPlayerCameraLookAt
#define Player_SetCameraBehind		SetCameraBehindPlayer

#define Player_SetWeather			SetPlayerWeather
#define Player_SetTime				SetPlayerTime


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


stock KPlayer_OnConnect(playerid)
{
	KPlayer_UpdateCamera(playerid);
}

stock KPlayer_OnSpawn(playerid)
{
	// todo: move to Open-GTO
	Player_SetPos(playerid, -2762.6882, 10.9242, 6.9015);
}

stock KPlayer_OnRequestClass(playerid, classid)
{
	#pragma unused classid
	// hide class selection buttons
	Player_ToggleSpectating(playerid, 1);
	Player_SetSpawnInfo(playerid, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	// set camera pos
	Timer_SetEx("KPlayer_UpdateCamera", 200, 0, "d", playerid);
	// set weather and time
	Player_SetWeather(playerid, 43);
	Player_SetTime(playerid, 0, 0);
	// show login dialog
	//
}

forward KPlayer_UpdateCamera(playerid);
public KPlayer_UpdateCamera(playerid)
{
	// todo: move to Open-GTO
	Player_SetCameraPos(playerid, -2785.616943, 26.270446, 17.054141);
	Player_SetCameraLookAt(playerid, -2775.761230, 15.552896, 12.677975);
}




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
