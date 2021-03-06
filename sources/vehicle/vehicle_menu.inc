/*

	About: vehicle user menu
	Author: ziggi
	
*/

#if defined _vehicle_menu_included
  #endinput
#endif

#define _vehicle_menu_included
#pragma library vehicle_menu


COMMAND:vmenu(playerid, params[])
{
	if (!IsPlayerInAnyVehicle(playerid)) {
		SendClientMessage(playerid, COLOUR_RED, lang_texts[5][1]);
		return 0;
	}
	
	Dialog_Show(playerid, Dialog:VehicleMenu);
	return 1;
}

DialogCreate:VehicleMenu(playerid)
{
	new string[512], engine, lights, alarm, doors, bonnet, boot, objective;
	new vehicleid = GetPlayerVehicleID(playerid);
	GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	
	strcat(string, "�����������\n", sizeof(string));
	strcat(string, "���������\n", sizeof(string));
	strcat(string, "�����\n", sizeof(string));
	strcat(string, "�������� ����\n", sizeof(string));
	
	// ����
	if (lights == VEHICLE_PARAMS_ON) {
		strcat(string, "{FF0000}���������  ����\n", sizeof(string));
	} else {
		strcat(string, "{00FF00}�������� ����\n", sizeof(string));
	}
	
	// ���������
	if (engine == VEHICLE_PARAMS_ON) {
		strcat(string, "{FF0000}��������� ���������\n", sizeof(string));
	} else {
		strcat(string, "{00FF00}�������� ���������\n", sizeof(string));
	}

	// �����
	if (bonnet == VEHICLE_PARAMS_ON) {
		strcat(string, "{FF0000}������� �����\n", sizeof(string));
	} else {
		strcat(string, "{00FF00}������� �����\n", sizeof(string));
	}
	
	// ��������
	if (boot == VEHICLE_PARAMS_ON) {
		strcat(string, "{FF0000}������� ��������\n", sizeof(string));
	} else {
		strcat(string, "{00FF00}������� ��������\n", sizeof(string));
	}
		
	Dialog_Open(playerid, Dialog:VehicleMenu, DIALOG_STYLE_LIST, "���� ����������", string, "��", "������");
}

DialogResponse:VehicleMenu(playerid, response, listitem, inputtext[])
{
	if (!response) {
		return 1;
	}

	new engine, lights, alarm, doors, bonnet, boot, objective;
	new vehicleid = GetPlayerVehicleID(playerid);
	GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);

	switch (listitem)
	{
		// �����������
		case 0: {
			new Float:float_tmp;
			GetVehicleZAngle(vehicleid, float_tmp);
			SetVehicleZAngle(vehicleid, float_tmp);
			return 1;
		}
		// ���������
		case 1: {
			if (vehicleid == 0) {
				Dialog_MessageEx(playerid, Dialog:VehicleReturnMenu, lang_texts[19][31], lang_texts[19][21], "�����", "������");
				return 1;
			}
			
			if (!IsPlayerAtFuelStation(playerid)) {
				Dialog_MessageEx(playerid, Dialog:VehicleReturnMenu, lang_texts[19][31], lang_texts[19][22], "�����", "������");
				return 1;
			}
			
			if (GetPVarInt(playerid, "Refueling")) {
				Dialog_MessageEx(playerid, Dialog:VehicleReturnMenu, lang_texts[19][31], lang_texts[19][23], "�����", "������");
				return 1;
			}
			
			new vehiclemodel = GetVehicleModel(vehicleid);
			switch (vehiclemodel) {
				case 481, 509, 510: {
					Dialog_MessageEx(playerid, Dialog:VehicleReturnMenu, lang_texts[19][31], lang_texts[19][24], "�����", "������");
					return 1;
				}
			}
			
			if (Fuel[vehicleid] >= FuelList[vehiclemodel-400]) {
				Dialog_MessageEx(playerid, Dialog:VehicleReturnMenu, lang_texts[19][31], lang_texts[19][25], "�����", "������");
				return 1;
			}
			
			SetPVarFloat(playerid, "OldFuel", Fuel[vehicleid]);
			fill_TimerID[playerid] = SetTimerEx("fill_Timer", 1000, 1, "i", playerid);
			SetPVarInt(playerid, "Refueling", 1);
			return 1;
		}
		// �����
		case 2: {
			Dialog_Show(playerid, Dialog:VehicleRadio);
			return 1;
		}
		// ����
		case 3: {
			Dialog_Show(playerid, Dialog:VehicleColor);
			return 1;
		}
		// ����
		case 4: {
			if (lights == VEHICLE_PARAMS_ON) {
				SetVehicleParamsEx(vehicleid, engine, VEHICLE_PARAMS_OFF, alarm, doors, bonnet, boot, objective);
			} else {
				SetVehicleParamsEx(vehicleid, engine, VEHICLE_PARAMS_ON, alarm, doors, bonnet, boot, objective);
			}
			return 1;
		}
		// ���������
		case 5: {
			if (engine == VEHICLE_PARAMS_ON) {
				SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_OFF, lights, alarm, doors, bonnet, boot, objective);
			} else {
				SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_ON, lights, alarm, doors, bonnet, boot, objective);
			}
			return 1;
		}
		// �����
		case 6: {
			if (bonnet == VEHICLE_PARAMS_ON) {
				SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, VEHICLE_PARAMS_OFF, boot, objective);
			} else {
				SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, VEHICLE_PARAMS_ON, boot, objective);
			}
			return 1;
		}
		// ��������
		case 7: {
			if (boot == VEHICLE_PARAMS_ON) {
				SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, VEHICLE_PARAMS_OFF, objective);
			} else {
				SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, VEHICLE_PARAMS_ON, objective);
			}
			return 1;
		}
	}
	return 1;
}

DialogCreate:VehicleColor(playerid)
{
	new string[MAX_NAME * COLOR_COUNT];

	for (new i = 0; i < COLOR_COUNT; i++) {
		format(string, sizeof(string), "%s{%s}%s\n", string, color_GetEmbeddingCode(i), color_GetName(i));
	}

	Dialog_Open(playerid, Dialog:VehicleColor, DIALOG_STYLE_LIST, "�������� ����", string, "��", "�����");
}

DialogResponse:VehicleColor(playerid, response, listitem, inputtext[])
{
	if (!response) {
		Dialog_Show(playerid, Dialog:VehicleMenu);
		return 1;
	}
	
	new vehicleid = GetPlayerVehicleID(playerid);
	ChangePlayerVehicleColor(playerid, vehicleid, color_GetVehicleCode(listitem), color_GetVehicleCode(listitem));
	return 1;
}

DialogResponse:VehicleReturnMenu(playerid, response, listitem, inputtext[])
{
	if (response) {
		Dialog_Show(playerid, Dialog:VehicleMenu);
	}
	return 1;
}
