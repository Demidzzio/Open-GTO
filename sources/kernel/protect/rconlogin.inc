/*
	
	About: rcon hack protect
	Author: ziggi
	
*/

#if defined _rconlogin_included
	#endinput
#endif

#define _rconlogin_included
#pragma library rconlogin


stock Rconlogin_OnRconLoginAttempt(ip[], password[], success)
{
	if (!gProtectConf[c_Rconlogin] || success) {
		return 0;
	}
	
	Log_Game(_(RCON_LOGIN_FAIL), ip, password);
	
	new player_ip[MAX_IP];
	foreach (new playerid : Player) {
		Player_GetIp(playerid, player_ip);
		
		if (!strcmp(ip, player_ip, false)) {
			Player_Kick(playerid, _(RCON_LOGIN_BAD_PASSWORD));
			return 1;
		}
	}
	return 1;
}
