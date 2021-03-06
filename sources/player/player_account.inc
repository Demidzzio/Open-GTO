/*

	About: player account login system
	Author:	Iain Gilbert
	Modified by GhostTT, ziggi

*/

#if defined _pl_account_included
	#endinput
#endif

#define _pl_account_included
#pragma library pl_account


#include "base"

stock account_LoadConfig(file_config)
{
	ini_getString(file_config, "Account_DB", AccountDB);
}

stock account_SaveConfig(file_config)
{
	ini_setString(file_config, "Account_DB", AccountDB);
}

stock account_Save(playerid)
{
	if (!player_IsLogin(playerid)) {
		return 0;
	}

	account_SaveEx(playerid);
	return 1;
}

stock account_SaveEx(playerid)
{
	new filename_account[MAX_STRING],
		temp[MAX_STRING],
		playername[MAX_PLAYER_NAME + 1];

	GetPlayerName(playerid, playername, sizeof(playername));

	format(filename_account, sizeof(filename_account), "%s%s"GTO_FILES_FORMAT, AccountDB, playername);

	new file_account;
	if (ini_fileExist(filename_account)) {
		file_account = ini_openFile(filename_account);
	} else {
		file_account = ini_createFile(filename_account);
	}

	GetPVarString(playerid, "Password", temp, sizeof(temp));
	ini_setString(file_account, "Password", temp);

	GetPVarString(playerid, "Creation_Date", temp, sizeof(temp));
	ini_setString(file_account, "Creation_Date", temp);

	GetPVarString(playerid, "Last_Login", temp, sizeof(temp));
	ini_setString(file_account, "Last_Login", temp);

	GetPVarString(playerid, "IP", temp, sizeof(temp));
	ini_setString(file_account, "LastIP", temp);

	ini_closeFile(file_account);
	return 1;
}

stock account_Register(playerid, password[])
{
	// set default data
#if defined USE_PASSWORD_ENCRYPT
	SetPVarString(playerid, "Password", encrypt(password));
#else
	SetPVarString(playerid, "Password", password);
#endif

	new date[20];
	GetCurrentDate(date);
	SetPVarString(playerid, "Creation_Date", date);
	
	// create account and player
	account_SaveEx(playerid);
	player_Create(playerid);

	// login
	account_Login(playerid, password);

	SendClientMessage(playerid, COLOUR_GREEN, lang_texts[1][12]);
	GameMSG("create_account: success %s(%d)", oGetPlayerName(playerid), playerid);
	return 1;
}

stock account_Login(playerid, password[])
{
	new filename_account[MAX_STRING],
		playername[MAX_PLAYER_NAME + 1];
	
	GetPlayerName(playerid, playername, sizeof(playername));
	format(filename_account, sizeof(filename_account), "%s%s"GTO_FILES_FORMAT, AccountDB, playername);
	
	if (!ini_fileExist(filename_account)) {
		return 0;
	}

	new dbpassword[MAX_PASS_LEN],
		file_account = ini_openFile(filename_account);

	ini_getString(file_account, "Password", dbpassword);

#if defined USE_PASSWORD_ENCRYPT
	set(password, encrypt(password));
#endif

	if (strcmp(password, dbpassword, false)) {
		ini_closeFile(file_account);

		GameMSG("player_login: failed: incorrect password by %s(%d)", playername, playerid);
		
		GivePVarInt(playerid, "Player_Login_Attempt", 1);
		if (GetPVarInt(playerid, "Player_Login_Attempt") >= MAX_PLAYER_LOGIN_ATTEMPT) {
			SendClientMessage(playerid, COLOUR_RED, lang_texts[1][7]);
			KickPlayer(playerid, lang_texts[1][4]);
		} else {
			Dialog_Show(playerid, Dialog:AccountLogin);
		}
		return 0;
	}

	SetPVarString(playerid, "Password", password);
	
	new date[20];
	ini_getString(file_account, "Creation_Date", date);
	SetPVarString(playerid, "Creation_Date", date);
	
	GetCurrentDate(date);
	SetPVarString(playerid, "Last_Login", date);
	
	ini_closeFile(file_account);

	// login player
	player_Login(playerid);
	return 1;
}

DialogCreate:AccountRegister(playerid)
{
	new string[MAX_STRING + MAX_PLAYER_NAME + 1],
		playername[MAX_PLAYER_NAME + 1];

	GetPlayerName(playerid, playername, sizeof(playername));

	format(string, sizeof(string), lang_texts[1][44], VERSION, playername, MIN_PASS_LEN, MAX_PASS_LEN);
	Dialog_Open(playerid, Dialog:AccountRegister, DIALOG_STYLE_INPUT, "�����������", string, "��������", "");
}

DialogResponse:AccountRegister(playerid, response, listitem, inputtext[])
{
	new pass_len = strlen(inputtext);
	if (pass_len >= MIN_PASS_LEN && pass_len <= MAX_PASS_LEN) {
		account_Register(playerid, inputtext);
	} else {
		Dialog_Show(playerid, Dialog:AccountRegister);
	}
	return 1;
}

DialogCreate:AccountLogin(playerid)
{
	new string[MAX_STRING + MAX_PLAYER_NAME + 1],
		playername[MAX_PLAYER_NAME + 1];

	GetPlayerName(playerid, playername, sizeof(playername));

	if (GetPVarInt(playerid, "Player_Login_Attempt") > 0) {
		format(string, sizeof(string), lang_texts[1][47], VERSION, playername, MAX_PLAYER_LOGIN_ATTEMPT - GetPVarInt(playerid, "Player_Login_Attempt"));
	} else {
		format(string, sizeof(string), lang_texts[1][43], VERSION, playername);
	}
	Dialog_Open(playerid, Dialog:AccountLogin, DIALOG_STYLE_PASSWORD, "���� � �������", string, "�����", "");

}

DialogResponse:AccountLogin(playerid, response, listitem, inputtext[])
{
	new pass_len = strlen(inputtext);
	if (pass_len >= MIN_PASS_LEN && pass_len <= MAX_PASS_LEN) {
		account_Login(playerid, inputtext);
	} else {
		Dialog_Show(playerid, Dialog:AccountLogin);
	}
}

stock account_ShowDialog(playerid)
{
	new filename_account[MAX_STRING],
		playername[MAX_PLAYER_NAME + 1];
	
	GetPlayerName(playerid, playername, sizeof(playername));
	format(filename_account, sizeof(filename_account), "%s%s"GTO_FILES_FORMAT, AccountDB, playername);

	if (ini_fileExist(filename_account)) {
		Dialog_Show(playerid, Dialog:AccountLogin);
	} else {
		Dialog_Show(playerid, Dialog:AccountRegister);
	}
	return 1;
}
