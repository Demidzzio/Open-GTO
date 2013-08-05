/*
	
	About: mapicon streamer
	Author:	ziggi
	
*/

#if defined _mapicon_stream_included
	#endinput
#endif

#define _mapicon_stream_included
#pragma library mapicon_stream


enum info_MapIcon {
	icon_type,
	Float:Coord_X,
	Float:Coord_Y,
	Float:Coord_Z
};

static gIcons[MAX_ICONS + 1][info_MapIcon];
static bool:gIconsShowed[MAX_PLAYERS][MAX_ICONS + 1];
static gSlotIcons[MAX_PLAYERS][MAX_SHOWED_ICONS + 1];
static gIconsShowedCount[MAX_PLAYERS];


stock Icon_Create(markertype, Float:X, Float:Y, Float:Z)
{
	new icon_id = Icon_GetFreeSlot();
	if (icon_id == 0) {
		Log_Error(_(MAPICON_IS_MAX), MAX_ICONS);
		return 0;
	}
	gIcons[icon_id][icon_type] = markertype;
	gIcons[icon_id][Coord_X] = X;
	gIcons[icon_id][Coord_Y] = Y;
	gIcons[icon_id][Coord_Z] = Z;
	return icon_id;
}

stock Icon_Delete(icon_id)
{
	gIcons[icon_id][icon_type] = 0;
	gIcons[icon_id][Coord_X] = 0.0;
	gIcons[icon_id][Coord_Y] = 0.0;
	gIcons[icon_id][Coord_Z] = 0.0;
	foreach (new i : Player) {
		icon_Hide(i, icon_id);
	}
}

stock Icon_UpdatePlayerStream(playerid, icon_id)
{
	Icon_HouseFix(playerid, icon_id);
	Icon_BusinessFix(playerid, icon_id);
	new slot = icon_GetSlot(playerid, icon_id);
	RemovePlayerMapIcon(playerid, slot);
	SetPlayerMapIcon(playerid, slot, gIcons[icon_id][Coord_X], gIcons[icon_id][Coord_Y], gIcons[icon_id][Coord_Z], gIcons[icon_id][icon_type], 0, MAPICON_LOCAL);
}

stock Icon_UpdateStream(icon_id)
{
	foreach (new i : Player) {
		Icon_UpdatePlayerStream(i, icon_id);
	}
}

stock Icon_Timer(playerid)
{
	new inArea;
	for (new icon_id = 1; icon_id <= MAX_ICONS; icon_id++) {
		inArea = IsPlayerInRangeOfPoint(playerid, MAP_ICON_SHOW_DIST, gIcons[icon_id][Coord_X], gIcons[icon_id][Coord_Y], gIcons[icon_id][Coord_Z]);
		// если игрок не в зоне отображения иконки, но иконка ототбражается
		if (!inArea && icon_IsValid(icon_id) && Icon_IsShowed(playerid, icon_id)) {
			Icon_Hide(playerid, icon_id);
			continue;
		}
		
		// если иконка показана или иконки нет
		if (Icon_IsShowed(playerid, icon_id) || !Icon_IsValid(icon_id) || Icon_GetShowedCount(playerid) >= MAX_SHOWED_ICONS) {
			continue;
		}
		
		// если игрок в зоне отображения иконки и нулевом интерьере
		if (inArea && GetPlayerInterior(playerid) == 0)  {
			Icon_HouseFix(playerid, icon_id);
			Icon_BusinessFix(playerid, icon_id);
			Icon_Show(playerid, icon_id);
		}
	}
}

stock Icon_IsShowed(playerid, icon_id)
{
	return gIconsShowed[playerid][icon_id];
}

stock Icon_Hide(playerid, icon_id)
{
	new slot = Icon_GetSlot(playerid, icon_id);
	RemovePlayerMapIcon(playerid, slot);
	gSlotIcons[playerid][slot] = 0;
	gIconsShowed[playerid][icon_id] = false;
	gIconsShowedCount[playerid]--;
}

stock Icon_Show(playerid, icon_id)
{
	new slot = Icon_GetFreePlayerSlot(playerid);
	SetPlayerMapIcon(playerid, slot, gIcons[icon_id][Coord_X], gIcons[icon_id][Coord_Y], gIcons[icon_id][Coord_Z], gIcons[icon_id][icon_type], 0, MAPICON_LOCAL);
	gSlotIcons[playerid][slot] = icon_id;
	gIconsShowed[playerid][icon_id] = true;
	gIconsShowedCount[playerid]++;
}

stock Icon_GetShowedCount(playerid)
{
	return gIconsShowedCount[playerid];
}

stock Icon_GetPos(icon_id, &Float:icon_x, &Float:icon_y, &Float:icon_z)
{
	if (!Icon_IsValid(icon_id)) {
		return 0;
	}
	icon_x = gIcons[icon_id][Coord_X];
	icon_y = gIcons[icon_id][Coord_Y];
	icon_z = gIcons[icon_id][Coord_Z];
	return 1;
}

stock Icon_GetIdByPos(Float:x, Float:y, Float:z)
{
	for (new icon_id = 1; icon_id <= MAX_ICONS; icon_id++) {
		if (x == gIcons[icon_id][Coord_X] && y == gIcons[icon_id][Coord_Y] && z == gIcons[icon_id][Coord_Z]) {
			return icon_id;
		}
	}
	return 0;
}

stock Icon_IsValid(icon_id)
{
	if (gIcons[icon_id][icon_type] == 0 && gIcons[icon_id][Coord_X] == 0.0 && gIcons[icon_id][Coord_Y] == 0.0 && gIcons[icon_id][Coord_Z] == 0.0) {
		return 0;
	}
	return 1;
}

stock Icon_GetFreeSlot()
{
	for (new icon_id = 1; icon_id <= MAX_ICONS; icon_id++) {
		if (!icon_IsValid(icon_id)) {
			return icon_id;
		}
	}
	return 0;
}

stock Icon_GetFreePlayerSlot(playerid)
{
	for (new slot = 1; slot <= MAX_SHOWED_ICONS; slot++) {
		if (gSlotIcons[playerid][slot] == 0) {
			return slot;
		}
	}
	return 0;
}

stock Icon_GetSlot(playerid, icon_id)
{
	for (new slot = 1; slot <= MAX_SHOWED_ICONS; slot++) {
		if (gSlotIcons[playerid][slot] == icon_id) {
			return slot;
		}
	}
	return 0;
}

stock Icon_HouseFix(playerid, icon_id)
{
	new playername[MAX_PLAYER_NAME+1];
	GetPlayerName(playerid, playername, sizeof(playername));
	
	for (new house_id = 0; house_id < sizeof(Houses); house_id++) {
		if (house_icon[house_id] != icon_id) {
			continue;
		}
		if (!strcmp(Houses[house_id][Houses_Owner], playername) || !strcmp(Houses[house_id][Houses_RentName], playername)) {
			gIcons[icon_id][icon_type] = 35;
		} else if (strcmp(Houses[house_id][Houses_Owner], "Unknown")) {
			gIcons[icon_id][icon_type] = 32;
		} else {
			gIcons[icon_id][icon_type] = 31;
		}
	}
}

stock Icon_BusinessFix(playerid, icon_id)
{
	new playername[MAX_PLAYER_NAME+1];
	GetPlayerName(playerid, playername, sizeof(playername));
	
	for (new bis_id = 0; bis_id < sizeof(Businesses); bis_id++) {
		if (business_icon[bis_id] != icon_id) {
			continue;
		}
		if (!strcmp(Businesses[bis_id][Business_Owner], playername)) {
			gIcons[icon_id][icon_type] = 38;
		} else if (strcmp(Businesses[bis_id][Business_Owner], "Unknown")) {
			gIcons[icon_id][icon_type] = 36;
		} else {
			gIcons[icon_id][icon_type] = 52;
		}
	}
}
