/*
	
	About: game configuration
	Author: ziggi
	
*/

#if defined _game_included
	#endinput
#endif

#define _game_included
#pragma library game


enum Config_Game {
	c_GameModeText[64],
	bool:c_UsePlayerPedAnims,
	bool:c_ShowNameTags,
	bool:c_ManualVehicleEngineAndLights,
	bool:c_ShowPlayerMarkers,
	c_ShowPlayerMarkersMode,
	Float:c_LimitPlayerMarkerRadius,
}

new gGameConf[Config_Game] = {
	GAME_MODE_TEXT,
	USE_PLAYER_PED_ANIMS,
	SHOW_NAME_TAGS,
	MANUAL_VEHICLE_PARAMS,
	SHOW_PLAYER_MARKERS,
	SHOW_PLAYER_MARKERS_MODE
};


stock Game_OnGameModeInit()
{
	SetGameModeText(gGameConf[c_GameModeText]);
	
	if (gGameConf[c_UsePlayerPedAnims]) {
		UsePlayerPedAnims();
	}
	if (gGameConf[c_ManualVehicleEngineAndLights]) {
		ManualVehicleEngineAndLights();
	}
	
	ShowNameTags(gGameConf[c_ShowNameTags]);
	
	if (gGameConf[c_ShowPlayerMarkers]) {
		ShowPlayerMarkers(gGameConf[c_ShowPlayerMarkersMode]);
	}

	LimitPlayerMarkerRadius(gGameConf[c_LimitPlayerMarkerRadius]);
	
	Log_Game(_(GAME_INIT));
}

stock Game_LoadConfig(file_cfg)
{
	ini_getString(file_cfg, "game_GameModeText", gGameConf[c_GameModeText]);
	ini_getInteger(file_cfg, "game_UsePlayerPedAnims", gGameConf[c_UsePlayerPedAnims]);
	ini_getInteger(file_cfg, "game_ShowNameTags", gGameConf[c_ShowNameTags]);
	ini_getInteger(file_cfg, "game_ManualVehicleEngineAndLights", gGameConf[c_ManualVehicleEngineAndLights]);
	ini_getInteger(file_cfg, "game_ShowPlayerMarkers", gGameConf[c_ShowPlayerMarkers]);
	ini_getInteger(file_cfg, "game_ShowPlayerMarkersMode", gGameConf[c_ShowPlayerMarkersMode]);
	ini_getFloat(file_cfg, "game_LimitPlayerMarkerRadius", gGameConf[c_LimitPlayerMarkerRadius]);
}

stock Game_SaveConfig(file_cfg)
{
	ini_setString(file_cfg, "game_GameModeText", gGameConf[c_GameModeText]);
	ini_setInteger(file_cfg, "game_UsePlayerPedAnims", gGameConf[c_UsePlayerPedAnims]);
	ini_setInteger(file_cfg, "game_ShowNameTags", gGameConf[c_ShowNameTags]);
	ini_setInteger(file_cfg, "game_ManualVehicleEngineAndLights", gGameConf[c_ManualVehicleEngineAndLights]);
	ini_setInteger(file_cfg, "game_ShowPlayerMarkers", gGameConf[c_ShowPlayerMarkers]);
	ini_setInteger(file_cfg, "game_ShowPlayerMarkersMode", gGameConf[c_ShowPlayerMarkersMode]);
	ini_setFloat(file_cfg, "game_LimitPlayerMarkerRadius", gGameConf[c_LimitPlayerMarkerRadius]);
}
