/*
	
	About: weapon hack protect
	Author: ziggi
	
*/

#if defined _pweapon_included
	#endinput
#endif

#define _pweapon_included
#pragma library pweapon


stock Weapon_OnPlayerPickUpPickup(playerid, pickupid)
{
	if (!gProtectConf[c_Weapon]) {
		return 0;
	}
	
	switch ( Pickup_GetModel(pickupid) ) {
		// parachute
		case 371: {
			Player_GiveWeapon(playerid, 46, 1);
		}
		// health
		case 1240: {
			Player_SetHealth(playerid, 100);
		}
		// armour
		case 1242: {
			Player_SetArmour(playerid, 100);
		}
	}
	return 1;
}

stock Weapon_OnPlayerExitVehicle(playerid, vehicleid)
{
	if (!gProtectConf[c_Weapon]) {
		return 0;
	}
	
	switch ( Vehicle_GetModel(vehicleid) ) {
		case 592,577,511,512,593,520,553,476,519,460,513,// самолёты
			 548,425,417,487,488,497,563,447,469: // вертолёты
		{
			Player_GiveWeapon(playerid, 46, 1);
		}
	}
	return 1;
}

stock Weapon_Check(playerid)
{
	if (!gProtectConf[c_Weapon]) {
		return 0;
	}
	
	new weapon_id, weapon_ammo;
	for (new i = 0; i < MAX_WEAPON_SLOT; i++) {
		GetPlayerWeaponData(playerid, i, weapon_id, weapon_ammo);
		
		if (weapon_id != 0 && (weapon_id != gPlayer[playerid][p_WeaponID][i] || weapon_ammo > gPlayer[playerid][p_WeaponAmmo][i])) {
			Player_Kick(playerid, _(WEAPON_HACK));
			return 1;
		}
		
		gPlayer[playerid][p_WeaponID][i] = weapon_id;
		gPlayer[playerid][p_WeaponAmmo][i] = (weapon_id == 0) ? 0 : weapon_ammo;
	}
	return 0;
}
