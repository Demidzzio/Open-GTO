/*
	
	About: vehicle functions
	Author: ziggi

*/

#if defined _vehicle_included
	#endinput
#endif

#define _vehicle_included
#pragma library vehicle


#define MAX_VEHICLE_COMPONENTS	14
#define MAX_VEHICLE_NAME		32

enum info_VehicleModel {
	Name[MAX_VEHICLE_NAME],
	Float:MaxSpeed
}

new gVehicleModel[][info_VehicleModel] = {
	{"Landstalker", 160},
	{"Bravura", 160},
	{"Buffalo", 200},
	{"Linerunner", 120},
	{"Perenniel", 150},
	{"Sentinel", 165},
	{"Dumper", 110},
	{"Firetruck", 170},
	{"Trashmaster", 110},
	{"Stretch", 180},
	{"Manana", 160},
	{"Infernus", 240},
	{"Voodoo", 160},
	{"Pony", 160},
	{"Mule", 140},
	{"Cheetah", 230},
	{"Ambulance", 155},
	{"Leviathan", 200},
	{"Moonbeam", 150},
	{"Esperanto", 160},
	{"Taxi", 180},
	{"Washington", 180},
	{"Bobcat", 165},
	{"Mr Whoopee", 145},
	{"BF Injection", 170},
	{"Hunter", 200},
	{"Premier", 200},
	{"Enforcer", 170},
	{"Securicar", 170},
	{"Banshee", 200},
	{"Predator", 190},
	{"Bus", 130},
	{"Rhino", 80},
	{"Barracks", 180},
	{"Hotknife", 200},
	{"Article Trailer", 120},
	{"Previon", 160},
	{"Coach", 160},
	{"Cabbie", 160},
	{"Stallion", 160},
	{"Rumpo", 160},
	{"RC Bandit", 75},
	{"Romero", 150},
	{"Packer", 150},
	{"Monster", 110},
	{"Admiral", 165},
	{"Squalo", 280},
	{"Seasparrow", 200},
	{"Pizzaboy", 190},
	{"Tram", 150},
	{"Article Trailer 2", 120},
	{"Turismo", 240},
	{"Speeder", 190},
	{"Reefer", 190},
	{"Tropic", 190},
	{"Flatbed", 140},
	{"Yankee", 160},
	{"Caddy", 160},
	{"Solair", 165},
	{"Topfun Van (Berkley's RC)", 160},
	{"Skimmer", 200},
	{"PCJ-600", 190},
	{"Faggio", 190},
	{"Freeway", 190},
	{"RC Baron", 75},
	{"RC Raider", 75},
	{"Glendale", 160},
	{"Oceanic", 160},
	{"Sanchez", 190},
	{"Sparrow", 200},
	{"Patriot", 170},
	{"Quad", 160},
	{"Coastguard", 190},
	{"Dinghy", 190},
	{"Hermes", 160},
	{"Sabre", 160},
	{"Rustler", 200},
	{"ZR-350", 200},
	{"Walton", 150},
	{"Regina", 165},
	{"Comet", 200},
	{"BMX", 120},
	{"Burrito", 150},
	{"Camper", 120},
	{"Marquis", 190},
	{"Baggage", 160},
	{"Dozer", 100},
	{"Maverick", 200},
	{"SAN News Maverick", 200},
	{"Rancher", 170},
	{"FBI Rancher", 170},
	{"Virgo", 160},
	{"Greenwood", 160},
	{"Jetmax", 190},
	{"Hotring Racer", 220},
	{"Sandking", 170},
	{"Blista Compact", 200},
	{"Police Maverick", 200},
	{"Boxville", 140},
	{"Benson", 140},
	{"Mesa", 160},
	{"RC Goblin", 75},
	{"Hotring Racer", 220},
	{"Hotring Racer", 220},
	{"Bloodring Banger", 160},
	{"Rancher", 170},
	{"Super GT", 230},
	{"Elegant", 165},
	{"Journey", 140},
	{"Bike", 120},
	{"Mountain Bike", 140},
	{"Beagle", 200},
	{"Cropduster", 200},
	{"Stuntplane", 200},
	{"Tanker", 120},
	{"Roadtrain", 120},
	{"Nebula", 165},
	{"Majestic", 165},
	{"Buccaneer", 160},
	{"Shamal", 330},
	{"Hydra", 330},
	{"FCR-900", 190},
	{"NRG-500", 190},
	{"HPV1000", 190},
	{"Cement Truck", 110},
	{"Towtruck", 160},
	{"Fortune", 160},
	{"Cadrona", 160},
	{"FBI Truck", 170},
	{"Willard", 160},
	{"Forklift", 60},
	{"Tractor", 70},
	{"Combine Harvester", 140},
	{"Feltzer", 200},
	{"Remington", 160},
	{"Slamvan", 160},
	{"Blade", 160},
	{"Freight (Train)", 110},
	{"Brownstreak (Train)", 110},
	{"Vortex", 150},
	{"Vincent", 160},
	{"Bullet", 230},
	{"Clover", 160},
	{"Sadler", 165},
	{"Firetruck LA", 170},
	{"Hustler", 160},
	{"Intruder", 160},
	{"Primo", 160},
	{"Cargobob", 200},
	{"Tampa", 160},
	{"Sunrise", 160},
	{"Merit", 165},
	{"Utility Van", 160},
	{"Nevada", 200},
	{"Yosemite", 170},
	{"Windsor", 180},
	{"Monster 'A'", 110},
	{"Monster 'B'", 110},
	{"Uranus", 200},
	{"Jester", 200},
	{"Sultan", 200},
	{"Stratum", 200},
	{"Elegy", 200},
	{"Raindance", 200},
	{"RC Tiger", 75},
	{"Flash", 200},
	{"Tahoma", 160},
	{"Savanna", 160},
	{"Bandito", 170},
	{"Freight Flat Trailer (Train)", 110},
	{"Streak Trailer (Train)", 110},
	{"Kart", 90},
	{"Mower", 60},
	{"Dune", 110},
	{"Sweeper", 60},
	{"Broadway", 160},
	{"Tornado", 160},
	{"AT400", 200},
	{"DFT-30", 110},
	{"Huntley", 160},
	{"Stafford", 165},
	{"BF-400", 190},
	{"Newsvan", 160},
	{"Tug", 170},
	{"Petrol Trailer", 120},
	{"Emperor", 165},
	{"Wayfarer", 190},
	{"Euros", 200},
	{"Hotdog", 140},
	{"Club", 200},
	{"Freight Box Trailer (Train)", 110},
	{"Article Trailer 3", 120},
	{"Andromada", 200},
	{"Dodo", 200},
	{"RC Cam", 60},
	{"Launch", 190},
	{"Police Car (LSPD)", 200},
	{"Police Car (SFPD)", 200},
	{"Police Car (LVPD)", 200},
	{"Police Ranger", 160},
	{"Picador", 165},
	{"S.W.A.T.", 110},
	{"Alpha", 200},
	{"Phoenix", 200}
	{"Glendale Shit", 160}
	{"Sadler Shit", 165},
	{"Baggage Trailer 'A'", 160},
	{"Baggage Trailer 'B'", 160},
	{"Tug Stairs Trailer", 160},
	{"Boxbville", 140},
	{"Farm Trailer", 160},
	{"Utility Trailer", 160}
};


enum info_Vehicle {
	Model,
	Float:SpawnPos[4],
	Float:OldPos[3],
	Color[2],
	Paintjobid,
	VirtualWorld,
	Interior,
	Float:Health,
	Component[MAX_VEHICLE_COMPONENTS],
	bool:Objective,
	bool:Doorslocked,
}

new gVehicle[MAX_VEHICLES][info_Vehicle] = {0};


stock vehicle_OnVehicleStreamIn(vehicleid, forplayerid)
{
	SetVehicleParamsForPlayer(vehicleid, forplayerid, gVehicle[vehicleid][Objective], gVehicle[vehicleid][Doorslocked]);
}

/*
	Name
*/

stock vehicle_SetName(model, name[MAX_VEHICLE_NAME])
{
	gVehicleModel[model - 400][Name] = name;
}

stock vehicle_GetName(model, name[], maxlength = sizeof(name))
{
	strmid(name, gVehicleModel[model - 400][Name], 0, maxlength);
}

/*
	Max speed
*/

stock vehicle_SetMaxSpeed(model, Float:speed)
{
	gVehicleModel[model - 400][MaxSpeed] = speed;
}

stock Float:vehicle_GetMaxSpeed(model)
{
	return gVehicleModel[model - 400][MaxSpeed];
}

/*
	Speed
*/

stock setVehicleSpeed ( vehicleid, speed_mph ) // by MX_Master
{
	if ( speed_mph < 1 ) speed_mph = 1;

	new Float: v[3], cur_speed_mph;
	GetVehicleVelocity( vehicleid, v[0], v[1], v[2] );
	cur_speed_mph = floatround( 100.0 * floatsqroot( v[0]*v[0] + v[1]*v[1] + v[2]*v[2] ), floatround_floor );

	if ( cur_speed_mph <= 0 )
	{
		new Float: zAngle;
		GetVehicleZAngle( vehicleid, zAngle );

		new Float: newVelX = floatcos( (zAngle -= 270.0), degrees ) * speed_mph / 100.0;
		SetVehicleVelocity( vehicleid, newVelX, floattan(zAngle,degrees) * newVelX, 0.0 );

		return;
	}

	new Float: vMultiplier = float(speed_mph) / float(cur_speed_mph);
	SetVehicleVelocity( vehicleid, v[0] * vMultiplier, v[1] * vMultiplier, v[2] * vMultiplier );
}

stock Float:vehicle_GetSpeed(vehicleid)
{
	new Float:vel[3];
	GetVehicleVelocity(vehicleid, vel[0], vel[1], vel[2]);
	return floatsqroot(vel[0] * vel[0] + vel[1] * vel[1] + vel[2] * vel[2]) * 100.0;
}

/*
	Distance
*/

stock Float:vehicle_GetPrevDist(vehicleid)
{
    new Float:dist = GetVehicleDistanceFromPoint(vehicleid, gVehicle[vehicleid][OldPos][0], gVehicle[vehicleid][OldPos][1], gVehicle[vehicleid][OldPos][2]);
    GetVehiclePos(vehicleid, gVehicle[vehicleid][OldPos][0], gVehicle[vehicleid][OldPos][1], gVehicle[vehicleid][OldPos][2]);
    return dist;
}

/*
	Create
*/

stock vehicle_Create(modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, respawn_delay, paintjobid=-1, virtualworld=0, interior=0, Float:health=1000.0, components[MAX_VEHICLE_COMPONENTS]={0})
{
	// todo: add check for trains
	
	new id = CreateVehicle(modelid, x, y, z, angle, color1, color2, respawn_delay);
	if (id == INVALID_VEHICLE_ID) {
		return INVALID_VEHICLE_ID;
	}
	gVehicle[id][Model] = modelid;
	gVehicle[id][SpawnPos][0] = x;
	gVehicle[id][SpawnPos][1] = y;
	gVehicle[id][SpawnPos][2] = z;
	gVehicle[id][SpawnPos][3] = angle;
	gVehicle[id][OldPos][0] = x;
	gVehicle[id][OldPos][1] = y;
	gVehicle[id][OldPos][2] = z;
	gVehicle[id][Color][0] = color1;
	gVehicle[id][Color][1] = color2;
	vehicle_ChangePaintjob(id, paintjobid);
	vehicle_SetVirtualWorld(id, virtualworld);
	vehicle_SetInterior(id, interior);
	vehicle_SetHealth(id, health);
	vehicle_AddComponentArray(id, components);
	return id;
}

/*
	Destroy
*/

stock vehicle_Destroy(vehicleid)
{
	gVehicle[vehicleid][Model] = 0;
	gVehicle[vehicleid][SpawnPos][0] = 0.0;
	gVehicle[vehicleid][SpawnPos][1] = 0.0;
	gVehicle[vehicleid][SpawnPos][2] = 0.0;
	gVehicle[vehicleid][SpawnPos][3] = 0.0;
	gVehicle[vehicleid][OldPos][0] = 0.0;
	gVehicle[vehicleid][OldPos][1] = 0.0;
	gVehicle[vehicleid][OldPos][2] = 0.0;
	gVehicle[vehicleid][Color][0] = 0;
	gVehicle[vehicleid][Color][1] = 0;
	gVehicle[vehicleid][Paintjobid] = 0;
	gVehicle[vehicleid][VirtualWorld] = 0;
	gVehicle[vehicleid][Health] = 0.0;
	return DestroyVehicle(vehicleid);
}

/*
	Position
*/

stock vehicle_SetPos(vehicleid, Float:x, Float:y, Float:z)
{
	foreach (new playerid : Player) {
		if (GetPlayerVehicleID(playerid) == vehicleid) {
			gPlayer[playerid][OldPos][0] = x;
			gPlayer[playerid][OldPos][1] = y;
			gPlayer[playerid][OldPos][2] = z;
		}
	}
	gVehicle[vehicleid][OldPos][0] = x;
	gVehicle[vehicleid][OldPos][1] = y;
	gVehicle[vehicleid][OldPos][2] = z;
	
	return SetVehiclePos(vehicleid, x, y, z);
}

stock vehicle_GetPos(vehicleid, &Float:x, &Float:y, &Float:z)
{
	return GetVehiclePos(vehicleid, x, y, z);
}

/*
	Rotation
*/

stock vehicle_SetZAngle(vehicleid, Float:angle)
{
	return SetVehicleZAngle(vehicleid, angle);
}

stock Float:vehicle_GetZAngle(vehicleid)
{
	return GetVehicleZAngle(vehicleid);
}

/*
	Color
*/

stock vehicle_ChangeColor(vehicleid, color1, color2)
{
	gVehicle[vehicleid][Color][0] = color1;
	gVehicle[vehicleid][Color][1] = color2;
	
	return ChangeVehicleColor(vehicleid, color1, color2);
}

stock vehicle_GetColor(vehicleid, &color1, &color2)
{
	color1 = gVehicle[vehicleid][Color][0];
	color2 = gVehicle[vehicleid][Color][1];
	return 1;
}

/*
	Paintjob
*/

stock vehicle_ChangePaintjob(vehicleid, paintjobid)
{
	gVehicle[vehicleid][Paintjobid] = paintjobid;
	return ChangeVehiclePaintjob(vehicleid, paintjobid);
}

stock vehicle_GetPaintjob(vehicleid)
{
	return gVehicle[vehicleid][Paintjobid];
}

/*
	Virtual world
*/

stock vehicle_SetVirtualWorld(vehicleid, virtualworld)
{
	gVehicle[vehicleid][VirtualWorld] = virtualworld;
	return SetVehicleVirtualWorld(vehicleid, virtualworld);
}

stock vehicle_GetVirtualWorld(vehicleid)
{
	if (gVehicle[vehicleid][VirtualWorld] != GetVehicleVirtualWorld(vehicleid)) {
		// todo: cheat??
	}
	return gVehicle[vehicleid][VirtualWorld];
}

/*
	Health
*/

stock vehicle_SetHealth(vehicleid, health)
{
	gVehicle[vehicleid][Health] = health;
	return SetVehicleHealth(vehicleid, health);
}

stock Float:vehicle_GetHealth(vehicleid)
{
	if (gVehicle[vehicleid][Health] < GetVehicleHealth(vehicleid)) {
		// todo: cheat??
	}
	return gVehicle[vehicleid][Health];
}

stock vehicle_Repair(vehicleid)
{
	gVehicle[vehicleid][Health] = 1000.0;
	return RepairVehicle(vehicleid);
}

/*
	Spawn pos
*/

stock vehicle_SetSpawnPos(vehicleid, Float:x, Float:y, Float:z)
{
	gVehicle[vehicleid][SpawnPos][0] = x;
	gVehicle[vehicleid][SpawnPos][1] = y;
	gVehicle[vehicleid][SpawnPos][2] = z;
}

stock vehicle_GetSpawnPos(vehicleid, &Float:x, &Float:y, &Float:z)
{
	x = gVehicle[vehicleid][SpawnPos][0];
	y = gVehicle[vehicleid][SpawnPos][1];
	z = gVehicle[vehicleid][SpawnPos][2];
}

/*
	Spawn angle
*/

stock vehicle_SetSpawnZAngle(vehicleid, Float:angle)
{
	gVehicle[vehicleid][SpawnPos][3] = angle;
}

stock Floatvehicle_GetSpawnZAngle(vehicleid)
{
	return gVehicle[vehicleid][SpawnPos][3];
}

/*
	Respawn
*/

stock vehicle_Respawn(vehicleid)
{
	SetVehicleToRespawn(vehicleid);
	vehicle_SetPos(vehicleid, gVehicle[vehicleid][SpawnPos][0], gVehicle[vehicleid][SpawnPos][1], gVehicle[vehicleid][SpawnPos][2]);
	vehicle_SetZAngle(vehicleid, gVehicle[vehicleid][SpawnPos][3]);
}

/*
	Interior
*/

stock vehicle_SetInterior(vehicleid, interiorid)
{
	gVehicle[vehicleid][Interior] = interiorid;
	return LinkVehicleToInterior(vehicleid, interiorid);
}

stock vehicle_GetInterior(vehicleid)
{
	return gVehicle[vehicleid][Interior];
}

/*
	Trailer
*/

stock vehicle_GetTrailer(vehicleid)
{
	return GetVehicleTrailer(vehicleid);
}

/*
	Components
*/

stock vehicle_AddComponent(vehicleid, componentid)
{
	new slot = GetVehicleComponentType(componentid);
	gVehicle[vehicleid][Component][slot] = componentid;
	return AddVehicleComponent(vehicleid, componentid);
}

stock vehicle_AddComponentArray(vehicleid, components[])
{
	for (new i = 0; i < MAX_VEHICLE_COMPONENTS; i++) {
		vehicle_AddComponent(vehicleid, components[i]);
	}
}

stock vehicle_GetComponentInSlot(vehicleid, slot)
{
	if (gVehicle[vehicleid][Component][slot] != GetVehicleComponentInSlot(vehicleid, slot)) {
		// todo: cheat??
	}
	return gVehicle[vehicleid][Component][slot];
}

stock vehicle_RemoveComponent(vehicleid, componentid)
{
	new slot = GetVehicleComponentType(componentid);
	gVehicle[vehicleid][Component][slot] = 0;
	return RemoveVehicleComponent(vehicleid, componentid);
}

stock vehicle_RemoveComponentInSlot(vehicleid, slot)
{
	gVehicle[vehicleid][Component][slot] = 0;
	new componentid = GetVehicleComponentInSlot(vehicleid, slot)
	return RemoveVehicleComponent(vehicleid, componentid);
}

/*
	Damage status
*/

stock vehicle_UpdateDamageStatus(vehicleid, panels, doors, lights, tires)
{
	return vehicle_UpdateDamageStatus(vehicleid, panels, doors, lights, tires);
}

stock vehicle_GetDamageStatus(vehicleid, &panels, &doors, &lights, &tires)
{
	return GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
}

/*
	Params
*/

stock vehicle_SetParams(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective)
{
	return SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
}

stock vehicle_GetParams(vehicleid, &engine, &lights, &alarm, &doors, &bonnet, &boot, &objective)
{
	return SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
}

/*
	Door
*/

stock vehicle_SetDoorStatus(vehicleid, bool:isLock)
{
	new engine, lights, alarm, doors, bonnet, boot, objective;
	vehicle_GetParams(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	vehicle_SetParams(vehicleid, engine, lights, alarm, _:isLock, bonnet, boot, objective);
	
	gVehicle[vehicleid][Doorslocked] = isLock;
	
	foreach (new playerid : Player) {
		SetVehicleParamsForPlayer(vehicleid, playerid, gVehicle[vehicleid][Objective], _:isLock);
	}
}

stock bool:vehicle_GetDoorStatus(vehicleid)
{
	return gVehicle[vehicleid][Doorslocked];
}

/*
	Objective
*/

stock vehicle_SetObjectiveStatus(vehicleid, bool:isEnabled)
{
	new engine, lights, alarm, doors, bonnet, boot, objective;
	vehicle_GetParams(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	vehicle_SetParams(vehicleid, engine, lights, alarm, doors, bonnet, boot, _:isEnabled);
	
	gVehicle[vehicleid][Objective] = isEnabled;
	
	foreach (new playerid : Player) {
		SetVehicleParamsForPlayer(vehicleid, playerid, _:isEnabled, gVehicle[vehicleid][Doorslocked]);
	}
}

stock bool:vehicle_GetObjectiveStatus(vehicleid)
{
	return gVehicle[vehicleid][Objective];
}
