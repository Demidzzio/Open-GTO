/*
	
	About: rcon hack protect
	Author: ziggi
	
*/

#if defined _rconlogin_included
	#endinput
#endif

#define _rconlogin_included
#pragma library rconlogin


new bool:protect_rconlogin_enabled = PROTECT_RCON_LOGIN_ENABLED;

stock Rconlogin_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "protect_rconlogin_enabled", protect_rconlogin_enabled);
}

stock Rconlogin_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "protect_rconlogin_enabled", protect_rconlogin_enabled);
}

stock Rconlogin_OnRconLoginAttempt(ip[], password[], success)
{
	if (!protect_rconlogin_enabled || success) {
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
