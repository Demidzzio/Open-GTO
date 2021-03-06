/*

	About: admin ban system
	Author:	ziggi

*/

#if defined _adm_ban_included
	#endinput
#endif

#define _adm_ban_included
#pragma library adm_ban


stock oBan_Check(playerid)
{
	new filename[MAX_STRING];
	format(filename, sizeof(filename), "%s%s"GTO_FILES_FORMAT, BanDB, oGetPlayerName(playerid));
	
	if (!ini_fileExist(filename))
	{
		new plrIP[MAX_IP];
		GetPVarString(playerid, "IP", plrIP, sizeof(plrIP));
		format(filename, sizeof(filename), "%s%s"GTO_FILES_FORMAT, BanDB, plrIP);
		
		if (!ini_fileExist(filename))
		{
			return 0;
		}
	}
	
	new date[MAX_NAME], time, admin[MAX_PLAYER_NAME+1], reason[MAX_SEND_SYMBOLS];
	new file_ban_db = ini_openFile(filename);
	
	ini_getString(file_ban_db, "Date", date);
	ini_getInteger(file_ban_db, "Time", time);
	ini_getString(file_ban_db, "Admin", admin);
	ini_getString(file_ban_db, "Reason", reason);
	
	ini_closeFile(file_ban_db);
	
	new idx = 0,
		ban_day = strval( strcharsplit(date, idx, '.') ),
		ban_month = strval( strcharsplit(date, idx, '.') ),
		ban_year = strval( strcharsplit(date, idx, ',') ),
		ban_hour = strval( strcharsplit(date, idx, ':') ),
		ban_minute = strval( strcharsplit(date, idx, ':') ),
		ban_second = strval( strcharsplit(date, idx, ':') );
	
	new year, month, day;
	getdate(year, month, day);
	new hours, minutes, seconds;
	gettime(hours, minutes, seconds);
	
	new unban_time =
		DateToNum(ban_year, ban_month, ban_day, ban_hour, ban_minute, ban_second) + time
		-
		DateToNum(year, month, day, hours, minutes, seconds);
	
	new string[MAX_STRING];
	
	if (time == 0) {
		format(string, sizeof(string), lang_texts[13][48], time);
		unban_time = 1;
	} else {
		format(string, sizeof(string), lang_texts[13][49], time);
		if (unban_time > 0) {
			format(string, sizeof(string), lang_texts[13][50], string, unban_time);
		}
	}
	format(string, sizeof(string), lang_texts[13][51], admin, date, string, reason);
	SendClientMessage(playerid, COLOUR_RED, string);
	
	if (unban_time > 0) {
		KickPlayer(playerid, "ban check", 0);
	} else {
		ini_fileRemove(filename);
		SendClientMessage(playerid, COLOUR_RED, lang_texts[13][52]);
	}
	return 1;
}

stock oBan(user[], reason[], adminid, time_second=0)
{
	new date[MAX_NAME], year, month, day, hour, minute, second;
	getdate(year, month, day);
	gettime(hour, minute, second);
	format(date, sizeof(date), "%02d.%02d.%d, %02d:%02d:%02d", day, month, year, hour, minute, second);
	
	if (IsNumeric(user)) {
		set(user, oGetPlayerName(strval(user)));
	}
	
	new filename_ban[MAX_STRING];
	format(filename_ban, sizeof(filename_ban), "%s%s"GTO_FILES_FORMAT, BanDB, user);
	
	new file_ban_db = (!ini_fileExist(filename_ban)) ? ini_createFile(filename_ban) : ini_openFile(filename_ban);
	ini_setString(file_ban_db, "Date", date);
	ini_setInteger(file_ban_db, "Time", time_second);
	ini_setString(file_ban_db, "Admin", oGetPlayerName(adminid));
	ini_setString(file_ban_db, "Reason", reason);
	ini_closeFile(file_ban_db);
	
	new string[MAX_STRING];
	if (time_second == 0) {
		format(string, sizeof(string), lang_texts[13][48], time_second);
	} else {
		format(string, sizeof(string), lang_texts[13][49], time_second);
	}

	format(string, sizeof(string), lang_texts[12][97], user, date, oGetPlayerName(adminid), adminid, string);
	
	if (strlen(reason) > 0) {
		format(string, sizeof(string), lang_texts[12][98], string, reason);
	}
	SendClientMessageToAll(COLOUR_RED, string);

	// если юзер на сервере
	if (IsIP(user)) {
		new plrIP[MAX_IP];
		foreach (new playerid : Player) {
			GetPVarString(playerid, "IP", plrIP, sizeof(plrIP));
			if (!strcmp(user, plrIP, false)) {
				KickPlayer(playerid, "ban", 0);
			}
		}
	} else {
		foreach (new playerid : Player) {
			if (!strcmp(user, oGetPlayerName(playerid), false)) {
				KickPlayer(playerid, "ban", 0);
			}
		}
	}
	return 1;
}

COMMAND:ban(playerid, params[])
{
	if (!IsPlayerAdm(playerid)) {
		return 0;
	}

	if (isnull(params)) {
		SendClientMessage(playerid, COLOUR_RED, lang_texts[12][3]);
		return 1;
	}

	new idx = 0,
		user[MAX_PLAYER_NAME + 1],
		reason[MAX_SEND_SYMBOLS],
		time_string[10];
	
	set(user, strcharsplit(params, idx, ' '));
	set(time_string, strcharsplit(params, idx, ' '));

	new time_second = strval(time_string);
	new time_type = time_string[strlen(time_string) - 1];

	switch (time_type) {
		case 's', 'с': {

		}
		case 'm', 'м': {
			time_second *= 60;
		}
		case 'h', 'ч': {
			time_second *= 60 * 60;
		}
		case 'd', 'д': {
			time_second *= 60 * 60 * 24;
		}
		case 'y', 'г': {
			time_second *= 60 * 60 * 24 * 365;
		}
	}

	if (strlen(params[idx + 1]) > 0) {
		set(reason, params[idx + 1]);
	}
	
	if (!IsNumeric(user) && (strlen(user) < MIN_PLAYER_NAME || strlen(user) > MAX_PLAYER_NAME)) {
		SendClientMessage(playerid, COLOUR_RED, lang_texts[13][33]);
		return 1;
	}

	if (strlen(reason) > MAX_SEND_SYMBOLS) {
		new string[MAX_STRING];
		format(string, sizeof(string), lang_texts[13][34], MAX_SEND_SYMBOLS);
		SendClientMessage(playerid, COLOUR_RED, string);
		return 1;
	}

	oBan(user, reason, playerid, time_second);
	return 1;
}

COMMAND:unban(playerid, params[])
{
	if (!IsPlayerAdm(playerid)) {
		return 0;
	}

	if (isnull(params)) {
		SendClientMessage(playerid, COLOUR_RED, lang_texts[12][3]);
		return 1;
	}

	new idx = 0,
		user[MAX_PLAYER_NAME + 1];
	
	set(user, strcharsplit(params, idx, ' '));
	
	if (strlen(user) < MIN_PLAYER_NAME || strlen(user) > MAX_PLAYER_NAME) {
		SendClientMessage(playerid, COLOUR_RED, lang_texts[13][35]);
		return 1;
	}
	
	new filename[MAX_STRING];
	format(filename, sizeof(filename), "%s%s"GTO_FILES_FORMAT, BanDB, user);
	
	new string[MAX_STRING];

	if (ini_fileExist(filename)) {
		ini_fileRemove(filename);
		
		format(string, sizeof(string), lang_texts[13][57], user);
	} else {
		format(string, sizeof(string), lang_texts[13][58], user);
	}

	SendClientMessage(playerid, COLOUR_RED, string);
	return 1;
}