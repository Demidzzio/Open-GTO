/*
	
	About: weapon functions
	Author: ziggi
	
*/

#if defined _weapon_included
	#endinput
#endif

#define _weapon_included
#pragma library weapon


#define MAX_WEAPON_SLOT	13

stock Player_GiveWeapon(playerid, weaponid, ammo)
{
	new slot_id = Weapon_GetSlot(weaponid)
	gPlayer[playerid][p_WeaponID][slot_id] = weaponid;
	gPlayer[playerid][p_WeaponAmmo][slot_id] += ammo;
	
	GivePlayerWeapon(playerid, weaponid, ammo);
	return 1;
}

stock Player_ResetWeapon(playerid)
{
	for (new i = 0; i < MAX_WEAPON_SLOT; i++) {
		gPlayer[playerid][p_WeaponID][i] = 0;
		gPlayer[playerid][p_WeaponAmmo][i] = 0;
	}
	
	ResetPlayerWeapons(playerid);
	return 1;
}
