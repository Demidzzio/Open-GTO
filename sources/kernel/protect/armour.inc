/*

	About: armour anti cheat
	Author: ziggi

*/

#if defined _armour_included
	#endinput
#endif

#define _armour_included
#pragma library armour


stock Armour_OnPlayerPickUpPickup(playerid, pickupid)
{
	if (!gProtectConf[c_Armour]) {
		return 0;
	}
	if (GetPickupModel(pickupid) == 1242) {
		Player_SetArmour(playerid, 100);
	}
	return 1;
}

stock Armour_Check(playerid)
{
	if (!gProtectConf[c_Armour]) {
		return 0;
	}
	new Float:server_armour = Player_GetArmour(playerid);
	new Float:client_armour;
	GetPlayerArmour(playerid, client_armour);
	
	if (client_armour > server_armour) {
		Player_SetArmour(playerid, server_armour);
	} else if (client_armour < server_armour) {
		gPlayer[playerid][p_Armour] = client_armour;
	}
	return 1;
}
