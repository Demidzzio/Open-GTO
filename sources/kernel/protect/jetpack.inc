/*
	
	About: jetpack protect
	Author: ziggi
	
*/

#if defined _jetpack_included
	#endinput
#endif

#define _jetpack_included
#pragma library jetpack


stock Jetpack_Check(playerid)
{
	if (!gProtectConf[c_Jetpack]) {
		return 0;
	}
	if (Player_GetSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK) {
		Player_Kick(playerid, _(JETPACK_USING));
	}
	return 1;
}
