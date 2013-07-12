/*

	About: money functions
	Author: ziggi

*/

#if defined _player_money_included
	#endinput
#endif

#define _player_money_included
#pragma library player_money


stock player_SetMoney(playerid, money)
{
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, money);
	gPlayer[playerid][Money] = money;
	return 1;
}

stock player_GiveMoney(playerid, money, showtext = 0)
{
	if (money == 0) {
		return 0;
	}
	
	if (player_GetMoney(playerid) + money > PLAYER_MAX_MONEY) {
		money = PLAYER_MAX_MONEY - player_GetMoney(playerid);
		
		new player_name[MAX_PLAYER_MONEY + 1];
		player_GetName(playerid, player_name, sizeof(player_name));
		log_User(_(PLAYER_HAVE_MAX_MONEY), player_name, playerid);
	}
	
	return player_SetMoney(playerid, player_GetMoney(playerid) + money);
}

stock player_GetTotalMoney(playerid)
{
	return gPlayer[playerid][Money] + gPlayer[playerid][BankMoney];
}

stock player_GetMoney(playerid)
{
	return gPlayer[playerid][Money];
}

