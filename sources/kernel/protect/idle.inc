/*
	
	About: idle protect
	Author: ziggi
	
*/

#if defined _idle_included
	#endinput
#endif

#define _idle_included
#pragma library idle


stock Idle_Check(playerid)
{
	// todo: add admin ignoring
	if (!gProtectConf[c_Idle]) {
		return 0;
	}
	
	new Float:pos[3], Float:idle_pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	Player_GetIdlePos(playerid, idle_pos[0], idle_pos[1], idle_pos[2]);
	
	if (pos[0] == idle_pos[0] && pos[1] == idle_pos[1] && pos[2] == idle_pos[2]) {
		new idle_time = player_GetIdleTime(playerid) + 1;
		Player_SetIdleTime(playerid, idle_time);
		
		if (Idle_time > gProtectConf[c_IdleMax]) {
			Player_SetIdleTime(playerid, 0);
			Player_Kick(playerid, _(IDLE_KICK));
		} else if (idle_time > gProtectConf[c_IdleMax] - 1) {
			new string[MAX_STRING];
			format(string, sizeof(string), _(IDLE_INFO), protect_idle_max - 1);
			Player_SendMessage(playerid, 0xFF000000, string);
			Player_SendMessage(playerid, 0xFF000000, _(IDLE_LAST));
		}
	} else {
		Player_SetIdleTime(playerid, 0);
	}
	Player_SetIdlePos(playerid, pos[0], pos[1], pos[2]);
   	return 1;
}

stock Player_GetIdleTime(playerid)
{
	return PVar_GetInt(playerid, "IdleTime");
}

stock Player_SetIdleTime(playerid, time)
{
	if (time == 0) {
		PVar_Delete(playerid, "IdleTime");
	} else {
		PVar_SetInt(playerid, "IdleTime", time);
	}
}

stock Player_GetIdlePos(playerid, &Float:x, &Float:y, &Float:z)
{
	x = PVar_GetFloat(playerid, "IdlePos_X");
	y = PVar_GetFloat(playerid, "IdlePos_Y");
	z = PVar_GetFloat(playerid, "IdlePos_Z");
}

stock Player_SetIdlePos(playerid, Float:x, Float:y, Float:z)
{
	PVar_SetFloat(playerid, "IdlePos_X", x);
	PVar_SetFloat(playerid, "IdlePos_Y", y);
	PVar_SetFloat(playerid, "IdlePos_Z", z);
}
