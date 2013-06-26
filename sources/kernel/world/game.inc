/*
	
	About: game configuration
	Author: ziggi
	
*/

#if defined _game_included
	#endinput
#endif

#define _game_included
#pragma library game


static bool:gUsePlayerPedAnims = USE_PLAYER_PED_ANIMS;
static bool:gShowNameTags = SHOW_NAME_TAGS;
static bool:gManualVehicleParams = MANUAL_VEHICLE_PARAMS;
static bool:gShowPlayerMarkers = SHOW_PLAYER_MARKERS;
static gShowPlayerMarkersMode = SHOW_PLAYER_MARKERS_MODE;
static gGameModeText[32] = GAME_MODE_TEXT;

stock game_OnGameModeInit()
{
	SetGameModeText(gGameModeText);
	
	if (gUsePlayerPedAnims) {
		UsePlayerPedAnims();
	}
	if (gManualVehicleParams) {
		ManualVehicleEngineAndLights();
	}
	
	ShowNameTags(gShowNameTags);
	
	if (gShowPlayerMarkers) {
		ShowPlayerMarkers(gShowPlayerMarkersMode);
	}
	if (gShowPlayerMarkers) {
		ShowPlayerMarkers(gShowPlayerMarkersMode);
	}
	
	log_Game(_(GAME_INIT));
}

stock game_LoadConfig(file_cfg)
{
	ini_getString(file_cfg, "game_GameModeText", gGameModeText);
	ini_getInteger(file_cfg, "game_UsePlayerPedAnims", gUsePlayerPedAnims);
	ini_getInteger(file_cfg, "game_ShowNameTags", gShowNameTags);
	ini_getInteger(file_cfg, "game_ManualVehicleEngineAndLights", gManualVehicleParams);
	ini_getInteger(file_cfg, "game_ShowPlayerMarkers", gShowPlayerMarkers);
	ini_getInteger(file_cfg, "game_ShowPlayerMarkersMode", gShowPlayerMarkersMode);
	return 1;
}

stock game_SaveConfig(file_cfg)
{
	ini_setString(file_cfg, "game_GameModeText", gGameModeText);
	ini_setInteger(file_cfg, "game_UsePlayerPedAnims", gUsePlayerPedAnims);
	ini_setInteger(file_cfg, "game_ShowNameTags", gShowNameTags);
	ini_setInteger(file_cfg, "game_ManualVehicleEngineAndLights", gManualVehicleParams);
	ini_setInteger(file_cfg, "game_ShowPlayerMarkers", gShowPlayerMarkers);
	ini_setInteger(file_cfg, "game_ShowPlayerMarkersMode", gShowPlayerMarkersMode);
	return 1;
}
