/*

	About: money functions
	Author: ziggi

*/

#if defined _player_money_included
	#endinput
#endif

#define _player_money_included
#pragma library player_money


stock Player_ResetMoney(playerid)
{
	ResetPlayerMoney(playerid);
	gPlayer[playerid][money] = 0;
	return 1;
}

stock Player_SetMoney(playerid, money)
{
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, money);
	gPlayer[playerid][Money] = money;
	return 1;
}

stock Player_GiveMoney(playerid, money, showtext = 0)
{
	if (money == 0) {
		return 0;
	}
	
	if (Player_GetMoney(playerid) + money > PLAYER_MAX_MONEY) {
		money = PLAYER_MAX_MONEY - Player_GetMoney(playerid);
		
		new player_name[MAX_PLAYER_MONEY + 1];
		Player_GetName(playerid, player_name, sizeof(player_name));
		
		Log_User(_(PLAYER_HAVE_MAX_MONEY), player_name, playerid);
	}
	
	return Player_SetMoney(playerid, Player_GetMoney(playerid) + money);
}

stock Player_GetTotalMoney(playerid)
{
	return gPlayer[playerid][Money] + gPlayer[playerid][BankMoney];
}

stock Player_GetMoney(playerid)
{
	return gPlayer[playerid][Money];
}

