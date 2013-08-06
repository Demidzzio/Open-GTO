/*
	
	About: defines and default settings
	Author: ziggi

*/

#if defined _config_header_included
	#endinput
#endif

#define _config_header_included
#pragma library config_header

/*
	System
*/
#define GAME_MODE_VERSION		"2.0"
#define GAME_MODE_TEXT			"Open-GTO v"#GTO_VERSION
#define DATA_FILES_FORMAT		".ini"
#define DATA_FILES_FOLDER		"open-gto/"

#define LANG_USE				"russian"

#define FILE_CONFIG				(DATA_FILES_FOLDER "config"DATA_FILES_FORMAT)
#define ini_fileExist			fexist

/*
	Log
*/
#define LOG_PRINTING
#define LOG_GAME_ENABLED		true
#define LOG_USER_ENABLED		true
#define LOG_ERROR_ENABLED		true
#define LOG_DEBUG_ENABLED		true

/*
	Weather
*/
#define WEATHER_UPDATE_TIME		20

/*
	Skins
*/
#define SKINS_COST			0
#define SKINS_IGNORE		0, 74

/*
	Player
*/
#define PLAYER_MAX_MONEY		999999999
#define PLAYER_START_MONEY		1000

/*
	Protect
*/
#define PROTECT_MONEY_ENABLED		true
#define PROTECT_ARMOUR_ENABLED		true
#define PROTECT_HEALTH_ENABLED		true
#define PROTECT_PING_ENABLED		true
#define PROTECT_PING_MAX			500
#define PROTECT_RCON_LOGIN_ENABLED	true
#define PROTECT_JETPACK_ENABLED		true
#define PROTECT_CHAT_ENABLED		true
#define PROTECT_IDLE_ENABLED		false
#define PROTECT_IDLE_MAX			10
#define PROTECT_WEAPON_ENABLED		true
#define PROTECT_SPEED_ENABLED		true

/*
	Mapicon streamer
*/
#define MAX_ICONS					1000
#define MAX_SHOWED_ICONS			100 // sa-mp limit
#define MAP_ICON_SHOW_DIST			400

/*
	Checkpoint streamer
*/
/*#define MAX_CP			255
#define CP_SHOW_DIST	65000.0*/
