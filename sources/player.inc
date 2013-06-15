/*
	
	About: player
	Author: ziggi
	
*/

#if defined _player_included
	#endinput
#endif

#define _player_included
#pragma library player


enum info_Player {
	Money,
	BankMoney,
}
new gPlayer[MAX_PLAYERS][info_Player];

static gPlayerStartMoney = PLAYER_START_MONEY;

stock player_OnGameModeInit()
{
	player_LoadClass();
	return 1;
}

stock player_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "player_StartMoney", gPlayerStartMoney);
	return 1;
}

stock player_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "player_StartMoney", gPlayerStartMoney);
	return 1;
}

stock player_Create(playerid)
{
	player_SetMoney(playerid, gPlayerStartMoney);
	player_Save(playerid);
	return 1;
}

stock player_Save(playerid)
{
	return 1;
}

stock player_LoadClass()
{
	for(new i = 0; i <= 299; i++) {
		switch (i) {
			case SKINS_IGNORE: {
				continue;
			}
			default: {
				AddPlayerClass(i, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
			}
		}
	}
	log_Game(_(PLAYER_CLASSES_INIT));
}
