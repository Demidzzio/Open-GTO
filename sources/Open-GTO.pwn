/*
	
	About: Open-GTO The Next Generation
	Author: ziggi
	
*/

#include <..\compiler\includes\a_samp.inc>

#include "sources/config/config.h"

#include "sources/kernel/config/config.inc"
#include "sources/kernel/config/camera.inc"
#include "sources/kernel/lib/utils.inc"
#include "sources/kernel/lang/lang.inc"
#include "sources/kernel/log/log.inc"
#include "sources/kernel/lib/foreach.inc"
#include "sources/kernel/lib/mxINI.inc"

#include "sources/kernel/streamers/checkpoint.inc"
#include "sources/kernel/streamers/mapicon.inc"

#include "sources/kernel/weapon/drop.inc"
#include "sources/kernel/weapon/skill.inc"
#include "sources/kernel/weapon/weapon.inc"

#include "sources/kernel/world/game.inc"
#include "sources/kernel/world/weather.inc"
#include "sources/kernel/world/zones.inc"

#include "sources/kernel/admin/ban.inc"
#include "sources/kernel/admin/jail.inc"
#include "sources/kernel/admin/kick.inc"
#include "sources/kernel/admin/mute.inc"

#include "sources/kernel/player/player.inc"
#include "sources/kernel/player/armour.inc"
#include "sources/kernel/player/fightstyle.inc"
#include "sources/kernel/player/health.inc"
#include "sources/kernel/player/ip.inc"
#include "sources/kernel/player/level.inc"
#include "sources/kernel/player/money.inc"
#include "sources/kernel/player/payday.inc"
#include "sources/kernel/player/vehicle.inc"
#include "sources/kernel/player/vip.inc"
#include "sources/kernel/player/weapon.inc"
#include "sources/kernel/player/camera.inc"

#include "sources/kernel/vehicle/vehicle.inc"
#include "sources/kernel/vehicle/fuel.inc"
#include "sources/kernel/vehicle/lock.inc"
#include "sources/kernel/vehicle/speed.inc"

#include "sources/kernel/protect/protect.inc"
#include "sources/kernel/protect/armour.inc"
#include "sources/kernel/protect/chat.inc"
#include "sources/kernel/protect/health.inc"
#include "sources/kernel/protect/idle.inc"
#include "sources/kernel/protect/jetpack.inc"
#include "sources/kernel/protect/money.inc"
#include "sources/kernel/protect/ping.inc"
#include "sources/kernel/protect/rconlogin.inc"
#include "sources/kernel/protect/speed.inc"
#include "sources/kernel/protect/weapon.inc"

#include "sources/kernel/quest/quest.inc"

#include "sources/kernel/kernel.inc"


#include "sources/admin/commands.inc"
#include "sources/admin/menu.inc"
#include "sources/admin/admin.inc"

#include "sources/gang/commands.inc"
#include "sources/gang/menu.inc"
#include "sources/gang/gang.inc"

#include "sources/player/player.inc"
#include "sources/player/commands.inc"
#include "sources/player/menu.inc"

#include "sources/quest/deathmatch.inc"
#include "sources/quest/race.inc"
#include "sources/quest/swagup.inc"
#include "sources/quest/trucker.inc"

#include "sources/services/bank.inc"
#include "sources/services/bar.inc"
#include "sources/services/business.inc"
#include "sources/services/fastfood.inc"
#include "sources/services/fightstyle.inc"
#include "sources/services/housing.inc"
#include "sources/services/lottery.inc"
#include "sources/services/skinshop.inc"
#include "sources/services/vehshop.inc"
#include "sources/services/weaponshop.inc"

#include "sources/world/groundhold.inc"
#include "sources/world/world.inc"

#include "sources/config/config.inc"


main() {}

public OnGameModeInit()
{
	Log_Game("Open-GTO: init...");
	// load configure
	Config_OnGameModeInit();
	
	// kernel
	Kernel_OnGameModeInit();
	
	// init gm modules
	Player_OnGameModeInit();
	
	// save world
	Config_Save();
	
	Log_Game(_(GAME_MODE_INIT_COMPLETE));
	return 1;
}

public OnGameModeExit()
{
	Log_Game(_(GAME_MODE_EXIT));
	return 1;
}

public OnPlayerConnect(playerid)
{
    if (Player_IsNPC(playerid)) {
		return 1;
	}
	Kernel_OnPlayerConnect(playerid);
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	if (Player_IsNPC(playerid)) {
		return 1;
	}
	Kernel_OnPlayerDisconnect(playerid, reason);
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
	if (Player_IsNPC(playerid)) {
		return 1;
	}
	return 1;
}

public OnPlayerSpawn(playerid)
{
	if (Player_IsNPC(playerid)) {
		return 1;
	}
	Kernel_OnPlayerSpawn(playerid);
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	Kernel_OnRequestClass(playerid, classid);
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	Kernel_OnPlayerRequestSpawn(playerid);
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
