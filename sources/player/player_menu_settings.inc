/*

	About: settings user menu
	Author: ziggi
	
*/

#if defined _settings_menu_included
  #endinput
#endif

#define _settings_menu_included
#pragma library settings_menu


DialogCreate:PlayerSettingsMenu(playerid)
{
	Dialog_Open(playerid, Dialog:PlayerSettingsMenu, DIALOG_STYLE_LIST,
		"��� ���������",
		"��������� �������\n\
		�������� ���\n\
		�������� ������",
		"�������", "�����"
	);
}

DialogResponse:PlayerSettingsMenu(playerid, response, listitem, inputtext[])
{
	if (!response) {
		Dialog_Show(playerid, Dialog:PlayerMenu);
		return 1;
	}
	
	switch (listitem) {
		// ��������� �������
		case 0: {
			player_Save(playerid);
			account_Save(playerid);
			Dialog_MessageEx(playerid, Dialog:SettingsReturnMenu, "���������� ��������", lang_texts[1][45], "�����", "������");
			return 1;
		}
		// �������� ���
		case 1: {
			Dialog_Show(playerid, Dialog:PlayerChangeNickMenu);
			return 1;
		}
		// �������� ������
		case 2: {
			Dialog_Show(playerid, Dialog:PlayerChangePassMenu);
			return 1;
		}
	}
	return 1;
}

DialogCreate:PlayerChangeNickMenu(playerid)
{
	Dialog_Open(playerid, Dialog:PlayerChangeNickMenu, DIALOG_STYLE_INPUT, "��� ���������", "������� �������� ���", "��", "�����");
}

DialogResponse:PlayerChangeNickMenu(playerid, response, listitem, inputtext[])
{
	if (!response) {
		Dialog_Show(playerid, Dialog:PlayerSettingsMenu);
		return 1;
	}
	
	new string[MAX_STRING];
	if (oGetPlayerMoney(playerid) < CHANGE_NICK_COST) {
		format(string, sizeof(string), lang_texts[1][36], CHANGE_NICK_COST);
		Dialog_MessageEx(playerid, Dialog:SettingsReturnMenu, "��������� ����", string, "�����", "������");
		return 1;
	}
	new Account_NewName[MAX_PLAYER_NAME+1],
		Account_LastName[MAX_PLAYER_NAME+1];
	
	set(Account_LastName, oGetPlayerName(playerid));
	set(Account_NewName, inputtext);
	
	if (strlen(Account_NewName) < MIN_PLAYER_NAME) {
		format(string, sizeof(string), lang_texts[1][37], MIN_PLAYER_NAME);
		Dialog_MessageEx(playerid, Dialog:SettingsReturnMenu, "��������� ����", string, "�����", "������");
		return 1;
	}
	
	format(string, sizeof(string), "%s%s"GTO_FILES_FORMAT, AccountDB, Account_NewName);
	// ���� ���� ����, �� ������� �����-��
	if (ini_fileExist(string)) {
		Dialog_MessageEx(playerid, Dialog:SettingsReturnMenu, "��������� ����", lang_texts[1][9], "�����", "������");
		return 1;
	}
	// �������� ���
	if (!NameCharCheck(Account_NewName)) {
		format(string, sizeof(string), lang_texts[1][9], ALLOWED_NICK_SYMBOLS_STR);
		Dialog_MessageEx(playerid, Dialog:SettingsReturnMenu, "��������� ����", string, "�����", "������");
		return 1;
	}
	// ���������������
	if (SetPlayerName(playerid, Account_NewName) != 1) {
		format(string, sizeof(string), lang_texts[1][9], ALLOWED_NICK_SYMBOLS_STR);
		Dialog_MessageEx(playerid, Dialog:SettingsReturnMenu, "��������� ����", string, "�����", "������");
		return 1;
	}
	
	new gangid = player_GetGangID(playerid);
	if (gangid != 0) {
		gang_RenameMember(gangid, Account_LastName, Account_NewName);
	}
	
	housing_RenameOwner(Account_LastName, Account_NewName);
	business_RenameOwner(Account_LastName, Account_NewName);
	
	races_RenameBestPlayer(Account_LastName, Account_NewName);
	dm_RenameBestPlayer(Account_LastName, Account_NewName);
	
	player_Save(playerid);
	account_Save(playerid);
	
	format(string, sizeof(string), "%s%s"GTO_FILES_FORMAT, AccountDB, Account_LastName);
	if (ini_fileExist(string)) {
		ini_fileRemove(string);
	}

	format(string, sizeof(string), "%s%s"GTO_FILES_FORMAT, PlayerDB, Account_LastName);
	if (ini_fileExist(string)) {
		ini_fileRemove(string);
	}
	
	oGivePlayerMoney(playerid,-CHANGE_NICK_COST, 1);
	
	format(string, sizeof(string), lang_texts[1][38], Account_LastName, Account_NewName);
	Dialog_MessageEx(playerid, Dialog:SettingsReturnMenu, "��������� ����", string, "�����", "������");
	return 1;
}

DialogCreate:PlayerChangePassMenu(playerid)
{
	Dialog_Open(playerid, Dialog:PlayerChangePassMenu, DIALOG_STYLE_INPUT, "��� ���������", "������� �������� ������", "��", "�����");
}

DialogResponse:PlayerChangePassMenu(playerid, response, listitem, inputtext[])
{
	if (!response) {
		Dialog_Show(playerid, Dialog:PlayerSettingsMenu);
		return 1;
	}
	
	new string[MAX_STRING];
	if (oGetPlayerMoney(playerid) < CHANGE_PASS_COST) {
		format(string, sizeof(string), lang_texts[1][35], CHANGE_PASS_COST);
		Dialog_MessageEx(playerid, Dialog:SettingsReturnMenu, "��������� ������", string, "�����", "������");
		return 1;
	}

	new pass[MAX_STRING];
	set(pass, inputtext);

	if (strlen(pass) < MIN_PASS_LEN || strlen(pass) > MAX_PASS_LEN) {
		format(string, sizeof(string), lang_texts[1][13], MIN_PASS_LEN, MAX_PASS_LEN);
		Dialog_MessageEx(playerid, Dialog:SettingsReturnMenu, "��������� ������", string, "�����", "������");
		return 1;
	}

	format(string, sizeof(string), lang_texts[1][34], pass);
	Dialog_MessageEx(playerid, Dialog:SettingsReturnMenu, "��������� ������", string, "�����", "������");

#if defined USE_PASSWORD_ENCRYPT
	SetPVarString(playerid, "Password", encrypt(pass));
#else
	SetPVarString(playerid, "Password", pass);
#endif

	account_Save(playerid);
	oGivePlayerMoney(playerid,-CHANGE_PASS_COST, 1);
	return 1;
}

DialogResponse:SettingsReturnMenu(playerid, response, listitem, inputtext[])
{
	if (response) {
		Dialog_Show(playerid, Dialog:PlayerSettingsMenu);
	}
	return 1;
}