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


stock Kernel_LoadConfig(file_cfg)
{
	Game_LoadConfig(file_cfg);
	Log_LoadConfig(file_cfg);
	Lang_LoadConfig(file_cfg);
	Weather_LoadConfig(file_cfg);
	Protect_LoadConfig(file_cfg);
	Camera_LoadConfig(file_cfg);
}

stock Kernel_SaveConfig(file_cfg)
{
	Game_SaveConfig(file_cfg);
	Log_SaveConfig(file_cfg);
	Lang_SaveConfig(file_cfg);
	Weather_SaveConfig(file_cfg);
	Protect_SaveConfig(file_cfg);
	Camera_SaveConfig(file_cfg);
}
