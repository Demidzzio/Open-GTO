/*
	
	About: kernel config functions
	Author: ziggi
	
	TODO: �������� ������� ��� ����������� ���������� ������ ������� �� �� ����
	
*/

#if defined _kconfig_included
	#endinput
#endif

#define _kconfig_included
#pragma library kconfig


stock kernel_OnGameModeInit()
{
	// sa-mp settings
	UsePlayerPedAnims();
	ShowPlayerMarkers(1);
	ShowNameTags(1);
	ManualVehicleEngineAndLights();
	return 1;
}

stock kernel_LoadConfig(file_cfg)
{
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
	speed_SaveConfig(file_cfg)
	return 1;
}