/*
	
	About: config save/load functions
	Author: ziggi

*/

#if defined _config_included
	#endinput
#endif

#define _config_included
#pragma library config


stock Config_OnGameModeInit()
{
	// modules settings
	new file_cfg = ini_openFile(FILE_CONFIG);
	if (file_cfg >= 0) {
		Kernel_LoadConfig(file_cfg);
		Player_LoadConfig(file_cfg);
		
		ini_closeFile(file_cfg);
	}
	
	Log_Game("Config: configuration init");
	return 1;
}

stock Config_Save()
{
	new file_cfg = ini_openFile(FILE_CONFIG);
	if (file_cfg < 0) {
		file_cfg = ini_createFile(FILE_CONFIG);
	}
	
	Kernel_SaveConfig(file_cfg);
	Player_SaveConfig(file_cfg);
	
	ini_closeFile(file_cfg);
	
	Log_Game(_(CONFIG_SAVE));
	return 1;
}
