/*
	
	About: protect configuration
	Author: ziggi

*/

#if defined _protect_included
	#endinput
#endif

#define _protect_included
#pragma library protect


enum Config_Protect {
	bool:c_Armour,
	bool:c_Chat,
	bool:c_Health,
	bool:c_Idle,
	c_IdleTime,
	bool:c_Jetpack,
	bool:c_Money,
	bool:c_Ping,
	c_PingMax,
	bool:c_Rconlogin,
	bool:c_Speed,
	bool:c_Weapon,
}

new gProtectConf[Config_Protect] = {
	PROTECT_ARMOUR_ENABLED,
	PROTECT_CHAT_ENABLED,
	PROTECT_HEALTH_ENABLED,
	PROTECT_IDLE_ENABLED,
	PROTECT_IDLE_MAX,
	PROTECT_JETPACK_ENABLED,
	PROTECT_MONEY_ENABLED,
	PROTECT_PING_ENABLED,
	PROTECT_PING_MAX,
	PROTECT_RCON_LOGIN_ENABLED,
	PROTECT_SPEED_ENABLED,
	PROTECT_WEAPON_ENABLED
};


stock Protect_OnGameModeInit()
{
	// todo: set timers
}

stock Protect_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "protect_armour", gProtectConf[c_Armour]);
	ini_getInteger(file_cfg, "protect_chat", gProtectConf[c_Chat]);
	ini_getInteger(file_cfg, "protect_health", gProtectConf[c_Health]);
	ini_getInteger(file_cfg, "protect_idle", gProtectConf[c_Idle]);
	ini_getInteger(file_cfg, "protect_idle_time", gProtectConf[c_IdleTime]);
	ini_getInteger(file_cfg, "protect_jetpack", gProtectConf[c_Jetpack]);
	ini_getInteger(file_cfg, "protect_money", gProtectConf[c_Money]);
	ini_getInteger(file_cfg, "protect_ping", gProtectConf[c_Ping]);
	ini_getInteger(file_cfg, "protect_ping_max", gProtectConf[c_PingMax]);
	ini_getInteger(file_cfg, "protect_rconlogin", gProtectConf[c_Rconlogin]);
	ini_getInteger(file_cfg, "protect_speed", gProtectConf[c_Speed]);
	ini_getInteger(file_cfg, "protect_weapon", gProtectConf[c_Weapon]);
}

stock Protect_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "protect_armour", gProtectConf[c_Armour]);
	ini_setInteger(file_cfg, "protect_chat", gProtectConf[c_Chat]);
	ini_setInteger(file_cfg, "protect_health", gProtectConf[c_Health]);
	ini_setInteger(file_cfg, "protect_idle", gProtectConf[c_Idle]);
	ini_setInteger(file_cfg, "protect_idle_time", gProtectConf[c_IdleTime]);
	ini_setInteger(file_cfg, "protect_jetpack", gProtectConf[c_Jetpack]);
	ini_setInteger(file_cfg, "protect_money", gProtectConf[c_Money]);
	ini_setInteger(file_cfg, "protect_ping", gProtectConf[c_Ping]);
	ini_setInteger(file_cfg, "protect_ping_max", gProtectConf[c_PingMax]);
	ini_setInteger(file_cfg, "protect_rconlogin", gProtectConf[c_Rconlogin]);
	ini_setInteger(file_cfg, "protect_speed", gProtectConf[c_Speed]);
	ini_setInteger(file_cfg, "protect_weapon", gProtectConf[c_Weapon]);
}
