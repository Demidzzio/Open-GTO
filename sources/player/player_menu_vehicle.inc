/*

	About: vehicle user menu
	Author: ziggi
	
*/

#if defined _pl_vehicle_menu_included
  #endinput
#endif

#define _pl_vehicle_menu_included
#pragma library pl_vehicle_menu


DialogCreate:PlayerVehicleMenu(playerid)
{
	if (GetPlayerVehicleCount(playerid) == 0) {
		Dialog_MessageEx(playerid, Dialog:PlayerReturnMenu, "��� ���������", "� ��� ��� ����������", "�����", "������");
		return 1;
	}

	new string[MAX_NAME * MAX_PLAYER_VEHICLES];

	for (new i = 0; i < MAX_PLAYER_VEHICLES; i++) {
		if (IsValidPlayerVehicleSlot(playerid, i)) {
			format(string, sizeof(string), "%s%s\n", string, GetVehicleName(PlayerVehicle[playerid][i][pv_Model]));
		}
	}

	Dialog_Open(playerid, Dialog:PlayerVehicleMenu, DIALOG_STYLE_LIST, "��� ���������", string, "�����", "�����");
	return 1;
}

DialogResponse:PlayerVehicleMenu(playerid, response, listitem, inputtext[])
{
	if (!response) {
		Dialog_Show(playerid, Dialog:PlayerMenu);
		return 1;
	}

	pl_veh_menu_SetItemID(playerid, listitem);
	Dialog_Show(playerid, Dialog:PlayerVehicleList);
	return 1;
}

DialogCreate:PlayerVehicleList(playerid)
{
	new veh_slot = pl_veh_menu_GetItemID(playerid);

	for (new i = 0; i < MAX_PLAYER_VEHICLES; i++) {
		if (!IsValidPlayerVehicleSlot(playerid, i)) {
			veh_slot++;
			continue;
		}
		if (i == veh_slot) {
			break;
		}
	}

	pl_veh_menu_SetVehicleSlot(playerid, veh_slot);
	
	Dialog_Open(playerid, Dialog:PlayerVehicleList, DIALOG_STYLE_LIST,
		"��� ���������",
		"����������� � ����\n\
		�������\n\
		����� ������",
		"�������", "�����"
	);
}

DialogResponse:PlayerVehicleList(playerid, response, listitem, inputtext[])
{
	if (!response) {
		Dialog_Show(playerid, Dialog:PlayerVehicleMenu);
		return 1;
	}

	switch (listitem) {
		// ����������� � ����
		case 0: {
			if (GetPlayerInterior(playerid) != 0) {
				Dialog_MessageEx(playerid, Dialog:PlayerVehicleReturnMenu, "��� ���������", "����������� ��������� � ���� ����� ������ �� �����", "�����", "������");
				return 0;
			}

			new Float:pos[4];
			GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
			GetPlayerFacingAngle(playerid, pos[3]);
			CreatePlayerVehicle(playerid, pl_veh_menu_GetVehicleSlot(playerid), pos[0]+1, pos[1]+1, pos[2], pos[3]);
			return 1;
		}
		// �������
		case 1: {
			new slot = pl_veh_menu_GetVehicleSlot(playerid);
			
			oGivePlayerMoney(playerid, GetPlayerVehicleCostBySlot(playerid, slot) / 2, 1);
			RemovePlayerVehicle(playerid, slot);
			
			Dialog_MessageEx(playerid, Dialog:PlayerVehicleReturnMenu, "��� ���������", "������� ���������", "�����", "������");
			return 1;
		}
		// ����� ������
		case 2: {
			RemovePlayerVehicleComponents(playerid, pl_veh_menu_GetVehicleSlot(playerid));
	
			Dialog_MessageEx(playerid, Dialog:PlayerVehicleReturnMenu, "��� ���������", "������ ��� ������� ����", "�����", "������");
			return 1;
		}
	}

	pl_veh_menu_CleanMenuGarbage(playerid);
	return 1;
}

DialogResponse:PlayerVehicleReturnMenu(playerid, response, listitem, inputtext[])
{
	if (response) {
		Dialog_Show(playerid, Dialog:PlayerVehicleMenu);
	}
	return 1;
}

stock pl_veh_menu_GetItemID(playerid)
{
	return GetPVarInt(playerid, "pl_veh_menu_ItemID");
}

stock pl_veh_menu_SetItemID(playerid, itemid)
{
	SetPVarInt(playerid, "pl_veh_menu_ItemID", itemid);
}

stock pl_veh_menu_GetVehicleSlot(playerid)
{
	return GetPVarInt(playerid, "pl_veh_menu_VehicleSlot");
}

stock pl_veh_menu_SetVehicleSlot(playerid, itemid)
{
	SetPVarInt(playerid, "pl_veh_menu_VehicleSlot", itemid);
}

stock pl_veh_menu_CleanMenuGarbage(playerid)
{
	DeletePVar(playerid, "pl_veh_menu_VehicleSlot");
	DeletePVar(playerid, "pl_veh_menu_ItemID");
}
