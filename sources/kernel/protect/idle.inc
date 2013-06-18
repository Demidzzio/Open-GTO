/*
	
	About: idle protect
	Author: ziggi
	
*/

#if defined _idle_included
	#endinput
#endif

#define _idle_included
#pragma library idle


new protect_idle_Enabled = PROTECT_IDLE_ENABLED,
	protect_idle_Max = PROTECT_IDLE_MAX;

stock idle_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "protect_idle_Enabled", protect_idle_Enabled);
	ini_getInteger(file_cfg, "protect_idle_Max", protect_idle_Max);
	return 1;
}

stock idle_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "protect_idle_Enabled", protect_idle_Enabled);
	ini_setInteger(file_cfg, "protect_idle_Max", protect_idle_Max);
	return 1;
}

stock idle_Check(playerid)
{
	// todo: add admin ignoring
	if (!protect_idle_Enabled) {
		return 0;
	}
	
	new Float:pos[3], Float:idle_pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	player_GetIdlePos(playerid, idle_pos[0], idle_pos[1], idle_pos[2]);
	
	if (pos[0] == idle_pos[0] && pos[1] == idle_pos[1] && pos[2] == idle_pos[2]) {
		new idle_time = player_GetIdleTime(playerid) + 1;
		player_SetIdleTime(playerid, idle_time);
		
		if (idle_time > protect_idle_Max) {
			player_SetIdleTime(playerid, 0);
			player_Kick(playerid, _(IDLE_KICK));
		} else if (idle_time > protect_idle_Max - 1) {
			new string[MAX_STRING];
			format(string, sizeof(string), _(IDLE_INFO), protect_idle_Max - 1);
			SendClientMessage(playerid, 0xFF000000, string);
			SendClientMessage(playerid, 0xFF000000, _(IDLE_LAST));
		}
	} else {
		player_SetIdleTime(playerid, 0);
	}
	player_SetIdlePos(playerid, pos[0], pos[1], pos[2]);
   	return 1;
}

stock player_GetIdleTime(playerid)
{
	return GetPVarInt(playerid, "IdleTime");
}

stock player_SetIdleTime(playerid, time)
{
	if (time == 0) {
		DeletePVar(playerid, "IdleTime");
	} else {
		SetPVarInt(playerid, "IdleTime", time);
	}
}

stock player_GetIdlePos(playerid, &Float:x, &Float:y, &Float:z)
{
	x = GetPVarFloat(playerid, "IdlePos_X");
	y = GetPVarFloat(playerid, "IdlePos_Y");
	z = GetPVarFloat(playerid, "IdlePos_Z");
}

stock player_SetIdlePos(playerid, Float:x, Float:y, Float:z)
{
	SetPVarFloat(playerid, "IdlePos_X", x);
	SetPVarFloat(playerid, "IdlePos_Y", y);
	SetPVarFloat(playerid, "IdlePos_Z", z);
}
