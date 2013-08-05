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
	// protection
	Money_LoadConfig(file_cfg);
	Armour_LoadConfig(file_cfg);
	Health_LoadConfig(file_cfg);
	Rconlogin_LoadConfig(file_cfg);
	Jetpack_LoadConfig(file_cfg);
	Chat_LoadConfig(file_cfg);
	Idle_LoadConfig(file_cfg);
	Weapon_LoadConfig(file_cfg);
	Speed_LoadConfig(file_cfg);
	return 1;
}

stock Kernel_SaveConfig(file_cfg)
{
	Game_SaveConfig(file_cfg);
	Log_SaveConfig(file_cfg);
	Lang_SaveConfig(file_cfg);
	Weather_SaveConfig(file_cfg);
	// protection
	Money_SaveConfig(file_cfg);
	Armour_SaveConfig(file_cfg);
	Health_SaveConfig(file_cfg);
	Rconlogin_SaveConfig(file_cfg);
	Jetpack_SaveConfig(file_cfg);
	Chat_SaveConfig(file_cfg);
	Idle_SaveConfig(file_cfg);
	Weapon_SaveConfig(file_cfg);
	Speed_SaveConfig(file_cfg);
	return 1;
}
