/*
	
	About: vehicle functions
	Author: ziggi

*/

#if defined _vehicle_included
	#endinput
#endif

#define _vehicle_included
#pragma library vehicle


#define MAX_VEHICLE_NAME 32

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
}

new gVehicle[MAX_VEHICLES][info_Vehicle];

stock vehicle_GetName(model, name[], maxlength = sizeof(name))
{
	strmid(name, gVehicleModel[model - 400][Name], 0, maxlength);
}

stock Float:vehicle_GetMaxSpeed(model)
{
	return gVehicleModel[model - 400][MaxSpeed];
}

stock Float:vehicle_GetSpeed(vehicleid)
{
	new Float:pos[3];
	GetVehicleVelocity(vehicleid, pos[0], pos[1], pos[2]);
	return floatsqroot(pos[0] * pos[0] + pos[1] * pos[1] + pos[2] * pos[2]) * 100.0;
}

stock Float:vehicle_GetPrevDist(vehicleid)
{
    new Float:dist = GetVehicleDistanceFromPoint(vehicleid, gVehicle[vehicleid][OldPos][0], gVehicle[vehicleid][OldPos][1], gVehicle[vehicleid][OldPos][2]);
    GetVehiclePos(vehicleid, gVehicle[vehicleid][OldPos][0], gVehicle[vehicleid][OldPos][1], gVehicle[vehicleid][OldPos][2]);
    return dist;
}

stock vehicle_Create(modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, respawn_delay)
{
	new id = CreateVehicle(modelid, x, y, z, angle, color1, color2, respawn_delay);
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
	return id;
}

stock vehicle_Destroy(vehicleid)
{
	gVehicle[vehicleid][Model] = 0;
	gVehicle[id][SpawnPos][0] = 0.0;
	gVehicle[id][SpawnPos][1] = 0.0;
	gVehicle[id][SpawnPos][2] = 0.0;
	gVehicle[id][SpawnPos][3] = 0.0;
	gVehicle[id][OldPos][0] = 0.0;
	gVehicle[id][OldPos][1] = 0.0;
	gVehicle[id][OldPos][2] = 0.0;
	gVehicle[vehicleid][Color][0] = 0;
	gVehicle[vehicleid][Color][1] = 0;
	return DestroyVehicle(vehicleid);
}

stock vehicle_SetPos(vehicleid, Float:x, Float:y, Float:z)
{
	foreach (Player, playerid) {
		if (GetPlayerVehicleID(playerid) == vehicleid) {
			gPlayer[playerid][OldPos][0] = x;
			gPlayer[playerid][OldPos][1] = y;
			gPlayer[playerid][OldPos][2] = z;
		}
	}
	gVehicle[vehicleid][OldPos][0] = x;
	gVehicle[vehicleid][OldPos][1] = y;
	gVehicle[vehicleid][OldPos][2] = z;
	
	SetVehiclePos(vehicleid, x, y, z);
	return 1;
}
