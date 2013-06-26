/*
	
	About: kernel config functions
	Author: ziggi
	
	TODO: добавить дефайны для возможности отключения каждой функции не из ядра
	
*/

#if defined _kconfig_included
	#endinput
#endif

#define _kconfig_included
#pragma library kconfig


/*

	sa-mp default settings
	
*/
#define USE_PLAYER_PED_ANIMS		true
#define SHOW_NAME_TAGS				true
#define MANUAL_VEHICLE_PARAMS		true
#define SHOW_PLAYER_MARKERS			true
#define SHOW_PLAYER_MARKERS_MODE	PLAYER_MARKERS_MODE_GLOBAL


stock kernel_LoadConfig(file_cfg)
{
	game_LoadConfig(file_cfg);
	log_LoadConfig(file_cfg);
	lang_LoadConfig(file_cfg);
	weather_LoadConfig(file_cfg);
	// protection
	money_LoadConfig(file_cfg);
	armour_LoadConfig(file_cfg);
	health_LoadConfig(file_cfg);
	rconlogin_LoadConfig(file_cfg);
	jetpack_LoadConfig(file_cfg);
	chat_LoadConfig(file_cfg);
	idle_LoadConfig(file_cfg);
	weapon_LoadConfig(file_cfg);
	speed_LoadConfig(file_cfg);
	return 1;
}

stock kernel_SaveConfig(file_cfg)
{
	game_SaveConfig(file_cfg);
	log_SaveConfig(file_cfg);
	lang_SaveConfig(file_cfg);
	weather_SaveConfig(file_cfg);
	// protection
	money_SaveConfig(file_cfg);
	armour_SaveConfig(file_cfg);
	health_SaveConfig(file_cfg);
	rconlogin_SaveConfig(file_cfg);
	jetpack_SaveConfig(file_cfg);
	chat_SaveConfig(file_cfg);
	idle_SaveConfig(file_cfg);
	weapon_SaveConfig(file_cfg);
	speed_SaveConfig(file_cfg);
	return 1;
}
