/*

	About: health anti cheat
	Author: ziggi

*/

#if defined _protect_health_included
	#endinput
#endif

#define _protect_health_included
#pragma library protect_health


stock Health_OnPlayerPickUpPickup(playerid, pickupid)
{
	if (!gProtectConf[c_Health]) {
		return 0;
	}
	if (GetPickupModel(pickupid) == 1242) {
		Player_SetHealth(playerid, 100);
	}
	return 1;
}

stock Health_Check(playerid)
{
	if (!gProtectConf[c_Health]) {
		return 0;
	}
	new Float:server_health = Player_GetHealth(playerid);
	new Float:client_health;
	GetPlayerHealth(playerid, client_health);
	
	if (client_health > server_health) {
		Player_SetHealth(playerid, server_health);
	} else if (client_health < server_health) {
		gPlayer[playerid][p_Health] = client_health;
	}
	return 1;
}
