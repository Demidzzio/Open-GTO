/*

	About: money anti cheat
	Author: ziggi

*/

#if defined _money_included
	#endinput
#endif

#define _money_included
#pragma library money


stock Money_Check(playerid)
{
	if (!gProtectConf[c_Money]) {
		return 0;
	}
	new server_money = Player_GetMoney(playerid);
	new client_money = GetPlayerMoney(playerid);
	
	if (client_money > server_money) {
		Player_SetMoney(playerid, server_money);
	} else if (client_money < server_money) {
		gPlayer[playerid][p_Money] = client_money;
	}
	return 1;
}
