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
	{"Landstalker", 160.0},
	{"Bravura", 160.0},
	{"Buffalo", 200.0},
	{"Linerunner", 120.0},
	{"Perenniel", 150.0},
	{"Sentinel", 165.0},
	{"Dumper", 110.0},
	{"Firetruck", 170.0},
	{"Trashmaster", 110.0},
	{"Stretch", 180.0},
	{"Manana", 160.0},
	{"Infernus", 240.0},
	{"Voodoo", 160.0},
	{"Pony", 160.0},
	{"Mule", 140.0},
	{"Cheetah", 230.0},
	{"Ambulance", 155.0},
	{"Leviathan", 200.0},
	{"Moonbeam", 150.0},
	{"Esperanto", 160.0},
	{"Taxi", 180.0},
	{"Washington", 180.0},
	{"Bobcat", 165.0},
	{"Mr Whoopee", 145.0},
	{"BF Injection", 170.0},
	{"Hunter", 200.0},
	{"Premier", 200.0},
	{"Enforcer", 170.0},
	{"Securicar", 170.0},
	{"Banshee", 200.0},
	{"Predator", 190.0},
	{"Bus", 130.0},
	{"Rhino", 80.0},
	{"Barracks", 180.0},
	{"Hotknife", 200.0},
	{"Article Trailer", 120.0},
	{"Previon", 160.0},
	{"Coach", 160.0},
	{"Cabbie", 160.0},
	{"Stallion", 160.0},
	{"Rumpo", 160.0},
	{"RC Bandit", 75.0},
	{"Romero", 150.0},
	{"Packer", 150.0},
	{"Monster", 110.0},
	{"Admiral", 165.0},
	{"Squalo", 280.0},
	{"Seasparrow", 200.0},
	{"Pizzaboy", 190.0},
	{"Tram", 150.0},
	{"Article Trailer 2", 120.0},
	{"Turismo", 240.0},
	{"Speeder", 190.0},
	{"Reefer", 190.0},
	{"Tropic", 190.0},
	{"Flatbed", 140.0},
	{"Yankee", 160.0},
	{"Caddy", 160.0},
	{"Solair", 165.0},
	{"Topfun Van (Berkley's RC)", 160.0},
	{"Skimmer", 200.0},
	{"PCJ-600", 190.0},
	{"Faggio", 190.0},
	{"Freeway", 190.0},
	{"RC Baron", 75.0},
	{"RC Raider", 75.0},
	{"Glendale", 160.0},
	{"Oceanic", 160.0},
	{"Sanchez", 190.0},
	{"Sparrow", 200.0},
	{"Patriot", 170.0},
	{"Quad", 160.0},
	{"Coastguard", 190.0},
	{"Dinghy", 190.0},
	{"Hermes", 160.0},
	{"Sabre", 160.0},
	{"Rustler", 200.0},
	{"ZR-350", 200.0},
	{"Walton", 150.0},
	{"Regina", 165.0},
	{"Comet", 200.0},
	{"BMX", 120.0},
	{"Burrito", 150.0},
	{"Camper", 120.0},
	{"Marquis", 190.0},
	{"Baggage", 160.0},
	{"Dozer", 100.0},
	{"Maverick", 200.0},
	{"SAN News Maverick", 200.0},
	{"Rancher", 170.0},
	{"FBI Rancher", 170.0},
	{"Virgo", 160.0},
	{"Greenwood", 160.0},
	{"Jetmax", 190.0},
	{"Hotring Racer", 220.0},
	{"Sandking", 170.0},
	{"Blista Compact", 200.0},
	{"Police Maverick", 200.0},
	{"Boxville", 140.0},
	{"Benson", 140.0},
	{"Mesa", 160.0},
	{"RC Goblin", 75.0},
	{"Hotring Racer", 220.0},
	{"Hotring Racer", 220.0},
	{"Bloodring Banger", 160.0},
	{"Rancher", 170.0},
	{"Super GT", 230.0},
	{"Elegant", 165.0},
	{"Journey", 140.0},
	{"Bike", 120.0},
	{"Mountain Bike", 140.0},
	{"Beagle", 200.0},
	{"Cropduster", 200.0},
	{"Stuntplane", 200.0},
	{"Tanker", 120.0},
	{"Roadtrain", 120.0},
	{"Nebula", 165.0},
	{"Majestic", 165.0},
	{"Buccaneer", 160.0},
	{"Shamal", 330.0},
	{"Hydra", 330.0},
	{"FCR-900", 190.0},
	{"NRG-500", 190.0},
	{"HPV1000", 190.0},
	{"Cement Truck", 110.0},
	{"Towtruck", 160.0},
	{"Fortune", 160.0},
	{"Cadrona", 160.0},
	{"FBI Truck", 170.0},
	{"Willard", 160.0},
	{"Forklift", 60.0},
	{"Tractor", 70.0},
	{"Combine Harvester", 140.0},
	{"Feltzer", 200.0},
	{"Remington", 160.0},
	{"Slamvan", 160.0},
	{"Blade", 160.0},
	{"Freight (Train)", 110.0},
	{"Brownstreak (Train)", 110.0},
	{"Vortex", 150.0},
	{"Vincent", 160.0},
	{"Bullet", 230.0},
	{"Clover", 160.0},
	{"Sadler", 165.0},
	{"Firetruck LA", 170.0},
	{"Hustler", 160.0},
	{"Intruder", 160.0},
	{"Primo", 160.0},
	{"Cargobob", 200.0},
	{"Tampa", 160.0},
	{"Sunrise", 160.0},
	{"Merit", 165.0},
	{"Utility Van", 160.0},
	{"Nevada", 200.0},
	{"Yosemite", 170.0},
	{"Windsor", 180.0},
	{"Monster 'A'", 110.0},
	{"Monster 'B'", 110.0},
	{"Uranus", 200.0},
	{"Jester", 200.0},
	{"Sultan", 200.0},
	{"Stratum", 200.0},
	{"Elegy", 200.0},
	{"Raindance", 200.0},
	{"RC Tiger", 75.0},
	{"Flash", 200.0},
	{"Tahoma", 160.0},
	{"Savanna", 160.0},
	{"Bandito", 170.0},
	{"Freight Flat Trailer (Train)", 110.0},
	{"Streak Trailer (Train)", 110.0},
	{"Kart", 90.0},
	{"Mower", 60.0},
	{"Dune", 110.0},
	{"Sweeper", 60.0},
	{"Broadway", 160.0},
	{"Tornado", 160.0},
	{"AT400", 200.0},
	{"DFT-30", 110.0},
	{"Huntley", 160.0},
	{"Stafford", 165.0},
	{"BF-400", 190.0},
	{"Newsvan", 160.0},
	{"Tug", 170.0},
	{"Petrol Trailer", 120.0},
	{"Emperor", 165.0},
	{"Wayfarer", 190.0},
	{"Euros", 200.0},
	{"Hotdog", 140.0},
	{"Club", 200.0},
	{"Freight Box Trailer (Train)", 110.0},
	{"Article Trailer 3", 120.0},
	{"Andromada", 200.0},
	{"Dodo", 200.0},
	{"RC Cam", 60.0},
	{"Launch", 190.0},
	{"Police Car (LSPD)", 200.0},
	{"Police Car (SFPD)", 200.0},
	{"Police Car (LVPD)", 200.0},
	{"Police Ranger", 160.0},
	{"Picador", 165.0},
	{"S.W.A.T.", 110.0},
	{"Alpha", 200.0},
	{"Phoenix", 200.0},
	{"Glendale Shit", 160.0},
	{"Sadler Shit", 165.0},
	{"Baggage Trailer 'A'", 160.0},
	{"Baggage Trailer 'B'", 160.0},
	{"Tug Stairs Trailer", 160.0},
	{"Boxbville", 140.0},
	{"Farm Trailer", 160.0},
	{"Utility Trailer", 160.0}
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

new gVehicle[MAX_VEHICLES][info_Vehicle];


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

stock vehicle_SetSpeed ( vehicleid, speed_mph ) // by MX_Master
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
	new Float:angle;
	GetVehicleZAngle(vehicleid, angle);
	return angle;
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

stock vehicle_SetHealth(vehicleid, Float:health)
{
	gVehicle[vehicleid][Health] = health;
	return SetVehicleHealth(vehicleid, health);
}

stock Float:vehicle_GetHealth(vehicleid)
{
	new Float:oldHealth;
	GetVehicleHealth(vehicleid, oldHealth);
	if (gVehicle[vehicleid][Health] < oldHealth) {
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

stock Float:vehicle_GetSpawnZAngle(vehicleid)
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
	new componentid = GetVehicleComponentInSlot(vehicleid, slot);
	return RemoveVehicleComponent(vehicleid, componentid);
}

/*
	Damage status
*/

stock vehicle_UpdateDamageStatus(vehicleid, panels, doors, lights, tires)
{
	return UpdateDamageStatus(vehicleid, panels, doors, lights, tires);
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
