/*
	
	About: config save/load functions
	Author: ziggi

*/

#if defined _config_included
	#endinput
#endif

#define _config_included
#pragma library config


stock config_OnGameModeInit()
{
	// sa-mp settings
	SetGameModeText(GTO_TEXT);
	UsePlayerPedAnims();
	ShowPlayerMarkers(1);
	ShowNameTags(1);
	ManualVehicleEngineAndLights();
	
	// modules settings
	new file_cfg = ini_openFile(FILE_CONFIG);
	if (file_cfg > 0) {
		log_LoadConfig(file_cfg);
		lang_LoadConfig(file_cfg);
		weather_LoadConfig(file_cfg);
		player_LoadConfig(file_cfg);
		money_LoadConfig(file_cfg);
		
		ini_closeFile(file_cfg);
	}
	
	log_Game("Config: configuration init");
	return 1;
}

stock config_Save()
{
	new file_cfg = ini_openFile(FILE_CONFIG);
	if (file_cfg < 0) {
		file_cfg = ini_createFile(FILE_CONFIG);
	}
	
	log_SaveConfig(file_cfg);
	lang_SaveConfig(file_cfg);
	weather_SaveConfig(file_cfg);
	player_SaveConfig(file_cfg);
	money_SaveConfig(file_cfg);
	
	ini_closeFile(file_cfg);
	
	log_Game(_(CONFIG_SAVE));
	return 1;
}
