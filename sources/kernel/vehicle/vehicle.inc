/*
	
	About: vehicle functions
	Author: ziggi

*/

#if defined _Vehicle_included
	#endinput
#endif

#define _Vehicle_included
#pragma library Vehicle


#define MAX_VEHICLE_COMPONENTS	14
#define MAX_VEHICLE_NAME		32

enum Info_VehicleModel {
	vm_Name[MAX_VEHICLE_NAME],
	vm_MaxSpeed
}

new gVehicleModel[][Info_VehicleModel] = {
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
	{"Squalo", 190},
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
	{"Faggio", 260},
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
	{"Hotring Racer", 260},
	{"Hotring Racer", 260},
	{"Bloodring Banger", 160},
	{"Rancher", 260},
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
	{"Shamal", 340},
	{"Hydra", 340},
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
	{"Firetruck LA", 260},
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
	{"Wayfarer", 260},
	{"Euros", 200},
	{"Hotdog", 140},
	{"Club", 200},
	{"Freight Box Trailer (Train)", 260},
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
	{"Phoenix", 200},
	{"Glendale Shit", 260},
	{"Sadler Shit", 260},
	{"Baggage Trailer 'A'", 160},
	{"Baggage Trailer 'B'", 160},
	{"Tug Stairs Trailer", 160},
	{"Boxbville", 140},
	{"Farm Trailer", 160},
	{"Utility Trailer", 260}
};


enum Info_Vehicle {
	v_Model,
	Float:v_SpawnPos[4],
	Float:v_OldPos[3],
	v_Color[2],
	v_Paintjobid,
	v_VirtualWorld,
	v_Interior,
	Float:v_Health,
	v_Component[MAX_VEHICLE_COMPONENTS],
	bool:v_Objective,
	bool:v_Doorslocked,
}

new gVehicle[MAX_VEHICLES][Info_Vehicle];


stock Vehicle_OnVehicleStreamIn(vehicleid, forplayerid)
{
	SetVehicleParamsForPlayer(vehicleid, forplayerid, gVehicle[vehicleid][v_Objective], gVehicle[vehicleid][v_DoorsLocked]);
}

/*
	Name
*/

stock Vehicle_SetName(model, name[MAX_VEHICLE_NAME])
{
	gVehicleModel[model - 400][vm_Name] = name;
}

stock Vehicle_GetName(model, name[], maxlength = sizeof(name))
{
	strmid(name, gVehicleModel[model - 400][vm_Name], 0, maxlength);
}

/*
	Max speed
*/

stock Vehicle_SetMaxSpeed(model, speed)
{
	gVehicleModel[model - 400][vm_MaxSpeed] = speed;
}

stock Vehicle_GetMaxSpeed(model)
{
	return gVehicleModel[model - 400][vm_MaxSpeed];
}

/*
	Speed
*/

stock Vehicle_SetSpeed( vehicleid, speed_mph ) // by MX_Master
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

stock Vehicle_GetSpeed(vehicleid)
{
	new Float:vel[3];
	GetVehicleVelocity(vehicleid, vel[0], vel[1], vel[2]);
	return floatround(floatsqroot(vel[0] * vel[0] + vel[1] * vel[1] + vel[2] * vel[2]) * 100.0, floatround_round);
}

/*
	Distance
*/

stock Float:Vehicle_GetPrevDist(vehicleid)
{
    new Float:dist = GetVehicleDistanceFromPoint(vehicleid, gVehicle[vehicleid][v_OldPos][0], gVehicle[vehicleid][v_OldPos][1], gVehicle[vehicleid][v_OldPos][2]);
    GetVehiclePos(vehicleid, gVehicle[vehicleid][v_OldPos][0], gVehicle[vehicleid][v_OldPos][1], gVehicle[vehicleid][v_OldPos][2]);
    return dist;
}

/*
	Create
*/

stock Vehicle_Create(modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, respawn_delay, paintjobid=-1, virtualworld=0, interior=0, Float:health=1000.0, components[MAX_VEHICLE_COMPONENTS]={0})
{
	// todo: add check for trains
	
	new id = CreateVehicle(modelid, x, y, z, angle, color1, color2, respawn_delay);
	if (id == INVALID_VEHICLE_ID) {
		return INVALID_VEHICLE_ID;
	}
	gVehicle[id][v_Model] = modelid;
	gVehicle[id][v_SpawnPos][0] = x;
	gVehicle[id][v_SpawnPos][1] = y;
	gVehicle[id][v_SpawnPos][2] = z;
	gVehicle[id][v_SpawnPos][3] = angle;
	gVehicle[id][v_OldPos][0] = x;
	gVehicle[id][v_OldPos][1] = y;
	gVehicle[id][v_OldPos][2] = z;
	gVehicle[id][v_Color][0] = color1;
	gVehicle[id][v_Color][1] = color2;
	Vehicle_ChangePaintjob(id, paintjobid);
	Vehicle_SetVirtualWorld(id, virtualworld);
	Vehicle_SetInterior(id, interior);
	Vehicle_SetHealth(id, health);
	Vehicle_AddComponentArray(id, components);
	return id;
}

/*
	Destroy
*/

stock Vehicle_Destroy(vehicleid)
{
	gVehicle[vehicleid][v_Model] = 0;
	gVehicle[vehicleid][v_SpawnPos][0] = 0.0;
	gVehicle[vehicleid][v_SpawnPos][1] = 0.0;
	gVehicle[vehicleid][v_SpawnPos][2] = 0.0;
	gVehicle[vehicleid][v_SpawnPos][3] = 0.0;
	gVehicle[vehicleid][v_OldPos][0] = 0.0;
	gVehicle[vehicleid][v_OldPos][1] = 0.0;
	gVehicle[vehicleid][v_OldPos][2] = 0.0;
	gVehicle[vehicleid][v_Color][0] = 0;
	gVehicle[vehicleid][v_Color][1] = 0;
	gVehicle[vehicleid][v_Paintjobid] = 0;
	gVehicle[vehicleid][v_VirtualWorld] = 0;
	gVehicle[vehicleid][v_Health] = 0.0;
	return DestroyVehicle(vehicleid);
}

/*
	Position
*/

stock Vehicle_SetPos(vehicleid, Float:x, Float:y, Float:z)
{
	foreach (new playerid : Player) {
		if (GetPlayerVehicleID(playerid) == vehicleid) {
			gPlayer[playerid][v_OldPos][0] = x;
			gPlayer[playerid][v_OldPos][1] = y;
			gPlayer[playerid][v_OldPos][2] = z;
		}
	}
	gVehicle[vehicleid][v_OldPos][0] = x;
	gVehicle[vehicleid][v_OldPos][1] = y;
	gVehicle[vehicleid][v_OldPos][2] = z;
	
	return SetVehiclePos(vehicleid, x, y, z);
}

stock Vehicle_GetPos(vehicleid, &Float:x, &Float:y, &Float:z)
{
	return GetVehiclePos(vehicleid, x, y, z);
}

/*
	Rotation
*/

stock Vehicle_SetZAngle(vehicleid, Float:angle)
{
	return SetVehicleZAngle(vehicleid, angle);
}

stock Float:Vehicle_GetZAngle(vehicleid)
{
	new Float:angle;
	GetVehicleZAngle(vehicleid, angle);
	return angle;
}

/*
	Color
*/

stock Vehicle_ChangeColor(vehicleid, color1, color2)
{
	gVehicle[vehicleid][v_Color][0] = color1;
	gVehicle[vehicleid][v_Color][1] = color2;
	
	return ChangeVehicleColor(vehicleid, color1, color2);
}

stock Vehicle_GetColor(vehicleid, &color1, &color2)
{
	color1 = gVehicle[vehicleid][v_Color][0];
	color2 = gVehicle[vehicleid][v_Color][1];
	return 1;
}

/*
	Paintjob
*/

stock Vehicle_ChangePaintjob(vehicleid, paintjobid)
{
	gVehicle[vehicleid][v_Paintjobid] = paintjobid;
	return ChangeVehiclePaintjob(vehicleid, paintjobid);
}

stock Vehicle_GetPaintjob(vehicleid)
{
	return gVehicle[vehicleid][v_Paintjobid];
}

/*
	Virtual world
*/

stock Vehicle_SetVirtualWorld(vehicleid, virtualworld)
{
	gVehicle[vehicleid][v_VirtualWorld] = virtualworld;
	return SetVehicleVirtualWorld(vehicleid, virtualworld);
}

stock Vehicle_GetVirtualWorld(vehicleid)
{
	if (gVehicle[vehicleid][v_VirtualWorld] != GetVehicleVirtualWorld(vehicleid)) {
		// todo: cheat??
	}
	return gVehicle[vehicleid][v_VirtualWorld];
}

/*
	Health
*/

stock Vehicle_SetHealth(vehicleid, Float:health)
{
	gVehicle[vehicleid][v_Health] = health;
	return SetVehicleHealth(vehicleid, health);
}

stock Float:Vehicle_GetHealth(vehicleid)
{
	new Float:oldHealth;
	GetVehicleHealth(vehicleid, oldHealth);
	if (gVehicle[vehicleid][v_Health] < oldHealth) {
		// todo: cheat??
	}
	return gVehicle[vehicleid][v_Health];
}

stock Vehicle_Repair(vehicleid)
{
	gVehicle[vehicleid][v_Health] = 1000.0;
	return RepairVehicle(vehicleid);
}

/*
	Spawn pos
*/

stock Vehicle_SetSpawnPos(vehicleid, Float:x, Float:y, Float:z)
{
	gVehicle[vehicleid][v_SpawnPos][0] = x;
	gVehicle[vehicleid][v_SpawnPos][1] = y;
	gVehicle[vehicleid][v_SpawnPos][2] = z;
}

stock Vehicle_GetSpawnPos(vehicleid, &Float:x, &Float:y, &Float:z)
{
	x = gVehicle[vehicleid][v_SpawnPos][0];
	y = gVehicle[vehicleid][v_SpawnPos][1];
	z = gVehicle[vehicleid][v_SpawnPos][2];
}

/*
	Spawn angle
*/

stock Vehicle_SetSpawnZAngle(vehicleid, Float:angle)
{
	gVehicle[vehicleid][v_SpawnPos][3] = angle;
}

stock Float:Vehicle_GetSpawnZAngle(vehicleid)
{
	return gVehicle[vehicleid][v_SpawnPos][3];
}

/*
	Respawn
*/

stock Vehicle_Respawn(vehicleid)
{
	SetVehicleToRespawn(vehicleid);
	Vehicle_SetPos(vehicleid, gVehicle[vehicleid][v_SpawnPos][0], gVehicle[vehicleid][v_SpawnPos][1], gVehicle[vehicleid][v_SpawnPos][2]);
	Vehicle_SetZAngle(vehicleid, gVehicle[vehicleid][v_SpawnPos][3]);
}

/*
	Interior
*/

stock Vehicle_SetInterior(vehicleid, interiorid)
{
	gVehicle[vehicleid][v_Interior] = interiorid;
	return LinkVehicleToInterior(vehicleid, interiorid);
}

stock Vehicle_GetInterior(vehicleid)
{
	return gVehicle[vehicleid][v_Interior];
}

/*
	Trailer
*/

stock Vehicle_GetTrailer(vehicleid)
{
	return GetVehicleTrailer(vehicleid);
}

/*
	Components
*/

stock Vehicle_AddComponent(vehicleid, componentid)
{
	new slot = GetVehicleComponentType(componentid);
	gVehicle[vehicleid][v_Component][slot] = componentid;
	return AddVehicleComponent(vehicleid, componentid);
}

stock Vehicle_AddComponentArray(vehicleid, components[])
{
	for (new i = 0; i < MAX_VEHICLE_COMPONENTS; i++) {
		Vehicle_AddComponent(vehicleid, components[i]);
	}
}

stock Vehicle_GetComponentInSlot(vehicleid, slot)
{
	if (gVehicle[vehicleid][v_Component][slot] != GetVehicleComponentInSlot(vehicleid, slot)) {
		// todo: cheat??
	}
	return gVehicle[vehicleid][v_Component][slot];
}

stock Vehicle_RemoveComponent(vehicleid, componentid)
{
	new slot = GetVehicleComponentType(componentid);
	gVehicle[vehicleid][v_Component][slot] = 0;
	return RemoveVehicleComponent(vehicleid, componentid);
}

stock Vehicle_RemoveComponentInSlot(vehicleid, slot)
{
	gVehicle[vehicleid][v_Component][slot] = 0;
	new componentid = GetVehicleComponentInSlot(vehicleid, slot);
	return RemoveVehicleComponent(vehicleid, componentid);
}

/*
	Damage status
*/

stock Vehicle_UpdateDamageStatus(vehicleid, panels, doors, lights, tires)
{
	return UpdateDamageStatus(vehicleid, panels, doors, lights, tires);
}

stock Vehicle_GetDamageStatus(vehicleid, &panels, &doors, &lights, &tires)
{
	return GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
}

/*
	Params
*/

stock Vehicle_SetParams(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective)
{
	return SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
}

stock Vehicle_GetParams(vehicleid, &engine, &lights, &alarm, &doors, &bonnet, &boot, &objective)
{
	return SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
}

/*
	Door
*/

stock Vehicle_SetDoorStatus(vehicleid, bool:isLock)
{
	new engine, lights, alarm, doors, bonnet, boot, objective;
	Vehicle_GetParams(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	Vehicle_SetParams(vehicleid, engine, lights, alarm, _:isLock, bonnet, boot, objective);
	
	gVehicle[vehicleid][v_DoorsLocked] = isLock;
	
	foreach (new playerid : Player) {
		SetVehicleParamsForPlayer(vehicleid, playerid, gVehicle[vehicleid][v_Objective], _:isLock);
	}
}

stock bool:Vehicle_GetDoorStatus(vehicleid)
{
	return gVehicle[vehicleid][v_DoorsLocked];
}

/*
	Objective
*/

stock Vehicle_SetObjectiveStatus(vehicleid, bool:isEnabled)
{
	new engine, lights, alarm, doors, bonnet, boot, objective;
	Vehicle_GetParams(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	Vehicle_SetParams(vehicleid, engine, lights, alarm, doors, bonnet, boot, _:isEnabled);
	
	gVehicle[vehicleid][v_Objective] = isEnabled;
	
	foreach (new playerid : Player) {
		SetVehicleParamsForPlayer(vehicleid, playerid, _:isEnabled, gVehicle[vehicleid][v_DoorsLocked]);
	}
}

stock bool:Vehicle_GetObjectiveStatus(vehicleid)
{
	return gVehicle[vehicleid][v_Objective];
}
