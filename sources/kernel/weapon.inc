/*
	
	About: weapon functions
	Author: ziggi
	
*/

#if defined _weapon_included
	#endinput
#endif

#define _weapon_included
#pragma library weapon



stock player_GiveWeapon(playerid, weaponid, ammo)
{
	new slot_id = weapon_GetSlot(weaponid)
	gPlayer[playerid][WeaponID][slot_id] = weaponid;
	gPlayer[playerid][WeaponAmmo][slot_id] += ammo;
	
	GivePlayerWeapon(playerid, weaponid, ammo);
	return 1;
}

stock player_ResetWeapon(playerid)
{
	for (new i = 0; i < PLAYER_WEAPON_SLOTS; i++) {
		gPlayer[playerid][WeaponID][i] = 0;
		gPlayer[playerid][WeaponAmmo][i] = 0;
	}
	
	ResetPlayerWeapons(playerid);
	return 1;
}
