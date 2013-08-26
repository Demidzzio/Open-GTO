/*
	
	About: kernel player camera functions
	Author: ziggi
	
*/

#if defined _kpcamera_included
	#endinput
#endif

#define _kpcamera_included
#pragma library kpcamera


stock Player_SetDefaultCameraPos(playerid)
{
	Player_SetCameraPos(playerid, gCameraConf[c_DefaultCameraPos][0], gCameraConf[c_DefaultCameraPos][1], gCameraConf[c_DefaultCameraPos][2]);
	Player_SetCameraLookAt(playerid, gCameraConf[c_DefaultCameraLookAt][0], gCameraConf[c_DefaultCameraLookAt][1], gCameraConf[c_DefaultCameraLookAt][2]);
}
