/*

	About: health anti cheat
	Author: ziggi

*/

#if defined _health_included
	#endinput
#endif

#define _health_included
#pragma library health


new bool:protect_health_enabled = PROTECT_HEALTH_ENABLED;

stock Health_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "protect_health_enabled", protect_health_enabled);
}

stock Health_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "protect_health_enabled", protect_health_enabled);
}

stock Health_OnPlayerPickUpPickup(playerid, pickupid)
{
	if (!protect_health_enabled) {
		return 0;
	}
	if (GetPickupModel(pickupid) == 1242) {
		Player_SetHealth(playerid, 100);
	}
	return 1;
}

stock Health_Check(playerid)
{
	if (!protect_health_enabled) {
		return 0;
	}
	new Float:serverhealth = Player_GetHealth(playerid);
	new Float:clienthealth;
	GetPlayerHealth(playerid, clienthealth);
	
	if (clienthealth > serverhealth) {
		Player_SetHealth(playerid, serverhealth);
	} else if (clienthealth < serverhealth) {
		gPlayer[playerid][Health] = clienthealth;
	}
	return 1;
}
