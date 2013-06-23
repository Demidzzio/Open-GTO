/*
	
	About: Open-GTO The Next Generation
	Author: ziggi
	
*/

#include <..\compiler\includes\a_samp>

#include "config.h"

#include "kernel\config.inc"
#include "kernel\lib\utils"
#include "kernel\lang"
#include "kernel\log"
#include "kernel\lib\foreach"
#include "kernel\lib\mxINI"

#include "kernel\streamers\checkpoint"
#include "kernel\streamers\mapicon"

#include "kernel\weapon\drop"
#include "kernel\weapon\skill"
#include "kernel\weapon"

#include "kernel\world\enterexits"
#include "kernel\world\weather"
#include "kernel\world\zones"

#include "kernel\admin\ban"
#include "kernel\admin\jail"
#include "kernel\admin\kick"
#include "kernel\admin\mute"

#include "kernel\player.inc"
#include "kernel\player\armour"
#include "kernel\player\fightstyle"
#include "kernel\player\health"
#include "kernel\player\ip"
#include "kernel\player\level"
#include "kernel\player\money"
#include "kernel\player\payday"
#include "kernel\player\vehicle"
#include "kernel\player\vip"
#include "kernel\player\weapon"

#include "kernel\vehicle.inc"
#include "kernel\vehicle\fuel"
#include "kernel\vehicle\lock"
#include "kernel\vehicle\speed"

#include "kernel\protect\armour.inc"
#include "kernel\protect\chat.inc"
#include "kernel\protect\health.inc"
#include "kernel\protect\idle.inc"
#include "kernel\protect\jetpack.inc"
#include "kernel\protect\money.inc"
#include "kernel\protect\ping.inc"
#include "kernel\protect\rconlogin.inc"
#include "kernel\protect\speed.inc"
#include "kernel\protect\weapon.inc"

#include "kernel\quest"


#include "admin\commands"
#include "admin\menu"
#include "admin"

#include "gang\commands"
#include "gang\menu"
#include "gang"

#include "player"
#include "player\commands"
#include "player\menu"

#include "quest\deathmatch"
#include "quest\race"
#include "quest\swagup"
#include "quest\trucker"

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

#include "world\groundhold"
#include "world"

#include "config"


main() {}

public OnGameModeInit()
{
	log_Game("Open-GTO: init...");
	// kernel
	kernel_OnGameModeInit();
	
	// load configure
	config_OnGameModeInit();
	
	// init all modules
	lang_OnGameModeInit();
	log_OnGameModeInit();
	weather_OnGameModeInit();
	player_OnGameModeInit();
	
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
