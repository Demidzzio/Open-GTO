/*

	About: money anti cheat
	Author: ziggi

*/

#if defined _money_included
	#endinput
#endif

#define _money_included
#pragma library money


new bool:protect_money_enabled = PROTECT_MONEY_ENABLED;

stock Money_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "protect_money_enabled", protect_money_enabled);
}

stock Money_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "protect_money_enabled", protect_money_enabled);
}

stock Money_Check(playerid)
{
	if (!protect_money_enabled) {
		return 0;
	}
	new servermoney = Player_GetMoney(playerid);
	new clientmoney = GetPlayerMoney(playerid);
	
	if (clientmoney > servermoney) {
		Player_SetMoney(playerid, servermoney);
	} else if (clientmoney < servermoney) {
		gPlayer[playerid][Money] = clientmoney;
	}
	return 1;
}
