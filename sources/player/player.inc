/*
	
	About: player
	Author: ziggi
	
*/

#if defined _player_included
	#endinput
#endif

#define _player_included
#pragma library player


enum Config_Player {
	c_PlayerStartMoney,
}

new gPlayerConf[Config_Player] = {PLAYER_START_MONEY};


stock Player_OnGameModeInit()
{
	Player_LoadClass();
}

stock Player_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "player_start_money", gPlayerConf[c_PlayerStartMoney]);
}

stock Player_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "player_start_money", gPlayerConf[c_PlayerStartMoney]);
}

stock Player_Create(playerid)
{
	player_SetMoney(playerid, gPlayerConf[c_PlayerStartMoney]);
	player_Save(playerid);
	return 1;
}

stock Player_Save(playerid)
{
	return 1;
}

stock Player_LoadClass()
{
	for(new i = 0; i <= 299; i++) {
		switch (i) {
			case SKINS_IGNORE: {
				continue;
			}
			default: {
				Player_AddClass(i, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
			}
		}
	}
	Log_Game(_(PLAYER_CLASSES_INIT));
}
