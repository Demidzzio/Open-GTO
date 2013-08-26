/*
	
	About: kernel camera config functions
	Author: ziggi
	
*/

#if defined _kccamera_included
	#endinput
#endif

#define _kccamera_included
#pragma library kccamera


enum Config_Camera {
	Float:c_DefaultCameraPos[3],
	Float:c_DefaultCameraLookAt[3],
}

new gCameraConf[Config_Camera] = {
	{-2785.616943, 26.270446, 17.054141}, // camera pos
	{-2775.761230, 15.552896, 12.677975}  // look at
};

stock Camera_LoadConfig(file_cfg)
{
	// camera pos
	ini_getFloat(file_cfg, "camera_DefaultCameraPos_X", gCameraConf[c_DefaultCameraPos][0]);
	ini_getFloat(file_cfg, "camera_DefaultCameraPos_Y", gCameraConf[c_DefaultCameraPos][1]);
	ini_getFloat(file_cfg, "camera_DefaultCameraPos_Z", gCameraConf[c_DefaultCameraPos][2]);
	// look at
	ini_getFloat(file_cfg, "camera_DefaultCameraLookAt_X", gCameraConf[c_DefaultCameraLookAt][0]);
	ini_getFloat(file_cfg, "camera_DefaultCameraLookAt_Y", gCameraConf[c_DefaultCameraLookAt][1]);
	ini_getFloat(file_cfg, "camera_DefaultCameraLookAt_Z", gCameraConf[c_DefaultCameraLookAt][2]);
}

stock Camera_SaveConfig(file_cfg)
{
	// camera pos
	ini_setFloat(file_cfg, "camera_DefaultCameraPos_X", gCameraConf[c_DefaultCameraPos][0]);
	ini_setFloat(file_cfg, "camera_DefaultCameraPos_Y", gCameraConf[c_DefaultCameraPos][1]);
	ini_setFloat(file_cfg, "camera_DefaultCameraPos_Z", gCameraConf[c_DefaultCameraPos][2]);
	// look at
	ini_setFloat(file_cfg, "camera_DefaultCameraLookAt_X", gCameraConf[c_DefaultCameraLookAt][0]);
	ini_setFloat(file_cfg, "camera_DefaultCameraLookAt_Y", gCameraConf[c_DefaultCameraLookAt][1]);
	ini_setFloat(file_cfg, "camera_DefaultCameraLookAt_Z", gCameraConf[c_DefaultCameraLookAt][2]);
}
