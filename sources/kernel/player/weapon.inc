/*
	
	About: player weapon functions
	Author: ziggi
	
*/

#if defined _player_weapon_included
	#endinput
#endif

#define _player_weapon_included
#pragma library player_weapon


stock weapon_GetSlot(weaponid)
{
	switch (weaponid) {
	    case 0, 1: return 0;
	    case 2..9: return 1;
	    case 22..24: return 2;
	    case 25..27: return 3;
	    case 28, 29, 32: return 4;
	    case 30, 31: return 5;
	    case 33, 34: return 6;
	    case 35..38: return 7;
	    case 16..18,39: return 8;
	    case 41..43: return 9;
		case 10..15: return 10;
		case 45, 46: return 11;
		case 40: return 12;
		default: return -1;
	}
	return -1;
}
