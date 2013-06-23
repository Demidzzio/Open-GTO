/*
	
	About: weapon hack protect
	Author: ziggi
	
*/

#if defined _pweapon_included
	#endinput
#endif

#define _pweapon_included
#pragma library pweapon


new protect_weapon_Enabled = PROTECT_WEAPON_ENABLED;

stock weapon_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "protect_weapon_Enabled", protect_weapon_Enabled);
	return 1;
}

stock weapon_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "protect_weapon_Enabled", protect_weapon_Enabled);
	return 1;
}

stock weapon_OnPlayerPickUpPickup(playerid, pickupid)
{
	if (!protect_weapon_Enabled) {
		return 0;
	}
	
	switch ( GetPickupModel(pickupid) ) {
		// parachute
		case 371: {
			player_GiveWeapon(playerid, 46, 1);
		}
		// health
		case 1240: {
			player_SetHealth(playerid, 100);
		}
		// armour
		case 1242: {
			player_SetArmour(playerid, 100);
		}
	}
	return 1;
}

stock weapon_OnPlayerExitVehicle(playerid, vehicleid)
{
	if (!protect_weapon_Enabled) {
		return 0;
	}
	
	switch ( GetVehicleModel(vehicleid) ) {
		case 592,577,511,512,593,520,553,476,519,460,513,// �������
			 548,425,417,487,488,497,563,447,469: // ��������
		{
			player_GiveWeapon(playerid, 46, 1);
		}
	}
	return 1;
}

stock weapon_Check(playerid)
{
	if (!protect_weapon_Enabled) {
		return 0;
	}
	
	new weapon[2];
	for (new i = 0; i < PLAYER_WEAPON_SLOTS; i++) {
		GetPlayerWeaponData(playerid, i, weapon[0], weapon[1]);
		
		if ( weapon[0] != gPlayer[playerid][WeaponID][i] || weapon[1] > gPlayer[playerid][WeaponAmmo][i] ) {
			player_Kick(playerid, _(WEAPON_HACK));
		}
	}
	return 1;
}
