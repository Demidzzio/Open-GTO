/*

	About: armour anti cheat
	Author: ziggi

*/

#if defined _armour_included
	#endinput
#endif

#define _armour_included
#pragma library armour


new bool:protect_armour_enabled = PROTECT_ARMOUR_ENABLED;

stock Armour_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "protect_armour_enabled", protect_armour_enabled);
}

stock Armour_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "protect_armour_enabled", protect_armour_enabled);
}

stock Armour_OnPlayerPickUpPickup(playerid, pickupid)
{
	if (!protect_armour_enabled) {
		return 0;
	}
	if (GetPickupModel(pickupid) == 1242) {
		player_SetArmour(playerid, 100);
	}
	return 1;
}

stock Armour_Check(playerid)
{
	if (!protect_armour_enabled) {
		return 0;
	}
	new Float:serverarmour = Player_GetArmour(playerid);
	new Float:clientarmour;
	GetPlayerArmour(playerid, clientarmour);
	
	if (clientarmour > serverarmour) {
		Player_SetArmour(playerid, serverarmour);
	} else if (clientarmour < serverarmour) {
		gPlayer[playerid][Armour] = clientarmour;
	}
	return 1;
}
