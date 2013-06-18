/*

	About: health functions
	Author: ziggi

*/

#if defined _health_included
	#endinput
#endif

#define _health_included
#pragma library health


new protect_health_Enabled = PROTECT_HEALTH_ENABLED;

stock health_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "protect_health_Enabled", protect_health_Enabled);
	return 1;
}

stock health_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "protect_health_Enabled", protect_health_Enabled);
	return 1;
}

stock health_OnPlayerPickUpPickup(playerid, pickupid)
{
	if (!protect_health_Enabled) {
		return 0;
	}
	if (GetPickupModel(pickupid) == 1242) {
		player_SetHealth(playerid, 100);
	}
	return 1;
}

stock health_Check(playerid)
{
	if (!protect_health_Enabled) {
		return 0;
	}
	new Float:serverhealth = player_GetHealth(playerid);
	new Float:clienthealth;
	GetPlayerHealth(playerid, clienthealth);
	
	if (clienthealth > serverhealth) {
		player_SetHealth(playerid, serverhealth);
	} else if (clienthealth < serverhealth) {
		gPlayer[playerid][Health] = clienthealth;
	}
	return 1;
}
