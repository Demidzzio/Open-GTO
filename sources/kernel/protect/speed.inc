/*
	
	About: speed hack protect
	Author: ziggi
	
*/

#if defined _speed_included
	#endinput
#endif

#define _speed_included
#pragma library speed


stock Speed_Check(playerid)
{
	if (!gProtectConf[c_Speed]) {
		return 0;
	}
	
	new player_state = Player_GetState(playerid);
	if (player_state == PLAYER_STATE_ONFOOT) {
		new Float:player_speed = Player_GetSpeed(playerid);
		new Float:player_max_speed = Player_GetMaxSpeed(playerid);
		
		if (player_speed > player_max_speed) {
			Player_Kick(playerid, _(SPEED_PLAYER_HACK));
		}
	} else if (player_state == PLAYER_STATE_DRIVER) {
		new Float:vehicle_speed = Vehicle_GetSpeed(playerid);
		new Float:vehicle_max_Speed = Vehicle_GetMaxSpeed(playerid);
		
		if (vehicle_speed > vehicle_max_Speed) {
			Player_Kick(playerid, _(SPEED_VEHICLE_HACK));
		}
	}
	return 1;
}
