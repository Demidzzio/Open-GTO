/*
	
	About: speed hack protect
	Author: ziggi
	
*/

#if defined _speed_included
	#endinput
#endif

#define _speed_included
#pragma library speed


new protect_speed_Enabled = PROTECT_SPEED_ENABLED;

stock speed_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "protect_speed_Enabled", protect_speed_Enabled);
	return 1;
}

stock speed_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "protect_speed_Enabled", protect_speed_Enabled);
	return 1;
}

stock speed_Check(playerid)
{
	if (!protect_speed_Enabled) {
		return 0;
	}
	
	new playerState = GetPlayerState(playerid);
	if (playerState == PLAYER_STATE_ONFOOT) {
		new Float:playerSpeed = player_GetSpeed(playerid);
		new Float:playerMaxSpeed = player_GetMaxSpeed(playerid);
		
		if (playerSpeed > playerMaxSpeed) {
			player_Kick(playerid, _(SPEED_PLAYER_HACK));
		}
	} else if (playerState == PLAYER_STATE_DRIVER) {
		new Float:vehicleSpeed = vehicle_GetSpeed(playerid);
		new Float:vehicleMaxSpeed = vehicle_GetMaxSpeed(playerid);
		
		if (vehicleSpeed > vehicleMaxSpeed) {
			player_Kick(playerid, _(SPEED_VEHICLE_HACK));
		}
	}
	return 1;
}
