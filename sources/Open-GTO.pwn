/*
	
	About: Open-GTO The Next Generation
	Author: ziggi
	
*/

#include <..\compiler\includes\a_samp>

#include "config.h"

#include "lib\utils"
#include "lib\lang"
#include "lib\log"
#include "lib\foreach"
#include "lib\mxINI"

#include "config"

#include "admin\tools\ban"
#include "admin\tools\jail"
#include "admin\tools\kick"
#include "admin\tools\mute"
#include "admin\commands"
#include "admin\menu"
#include "admin"

#include "gang\commands"
#include "gang\menu"
#include "gang"

#include "player\tools\fightstyle"
#include "player\tools\level"
#include "player\tools\payday"
#include "player\tools\vehicle"
#include "player\tools\vip"
#include "player\tools\weapon"
#include "player\commands"
#include "player\menu"
#include "player"

#include "protect\armour"
#include "protect\chat"
#include "protect\health"
#include "protect\idle"
#include "protect\jetpack"
#include "protect\money"
#include "protect\ping"
#include "protect\rconlogin"
#include "protect\speed"
#include "protect\weapon"

#include "quest\deathmatch"
#include "quest\race"
#include "quest\swagup"
#include "quest\trucker"
#include "quest"

#include "services\bank"
#include "services\bar"
#include "services\business"
#include "services\fastfood"
#include "services\fightstyle"
#include "services\housing"
#include "services\lottery"
#include "services\skinshop"
#include "services\vehshop"
#include "services\weaponshop"

#include "streamers\checkpoint"
#include "streamers\mapicon"

#include "vehicle\fuel"
#include "vehicle\lock"
#include "vehicle\speed"
#include "vehicle"

#include "weapon\drop"
#include "weapon\skill"
#include "weapon"

#include "world\enterexits"
#include "world\groundhold"
#include "world\weather"
#include "world\zones"
#include "world"

main() {}

public OnGameModeInit()
{
	log_Game("Open-GTO: init...");
	// load configure
	config_OnGameModeInit();
	
	// init all modules
	lang_OnGameModeInit();
	log_OnGameModeInit();
	weather_OnGameModeInit();
	
	// save world
	config_Save();
	
	log_Game(_(GTO_INIT_COMPLETE));
	return 1;
}

public OnGameModeExit()
{
	log_Game(_(GTO_EXIT));
	return 1;
}

public OnPlayerConnect(playerid)
{
    if (IsPlayerNPC(playerid)) {
		return 1;
	}
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	if (IsPlayerNPC(playerid)) {
		return 1;
	}
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	return 1;
}

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
    return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	if (IsPlayerNPC(playerid)) {
		return 1;
	}
	return 1;
}

public OnPlayerSpawn(playerid)
{
	if (IsPlayerNPC(playerid)) {
		return 1;
	}
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	return 1;
}

public OnPlayerText(playerid, text[])
{
	return 0;
}

public OnPlayerUpdate(playerid)
{
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	return 1;
}

public OnPlayerSelectedMenuRow(playerid, row)
{
	return 1;
}

public OnPlayerExitedMenu(playerid)
{
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
    return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	return 1;
}

public OnPlayerStreamIn(playerid, forplayerid)
{
    return 1;
}

public OnPlayerStreamOut(playerid, forplayerid)
{
    return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
	return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid)
{
	return 1;
}

public OnVehicleDamageStatusUpdate(vehicleid, playerid)
{
	return 1;
}

public OnVehicleStreamIn(vehicleid, forplayerid)
{
    return 1;
}

public OnVehicleStreamOut(vehicleid, forplayerid)
{
    return 1;
}

public OnVehicleSpawn(vehicleid)
{
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
    return 1;
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	return 1;
}

public OnEnterExitModShop(playerid, enterexit, interiorid)
{
	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	return 1;
}
