/*
	
	About: language functions
	Author: ziggi

*/

#if defined _lang_included
	#endinput
#endif

#define _lang_included
#pragma library lang


#define MAX_LANG_STRING	(MAX_STRING + 32)
#define MAX_VAR_STRING	32

#define _(%0) Lang_GetText(#%0)

static g_lang_use[16] = LANG_USE;

stock Lang_OnGameModeInit()
{
	new lang_file[MAX_STRING];
	format(lang_file, sizeof(lang_file), DATA_FILES_FOLDER "lang/%s"DATA_FILES_FORMAT, g_lang_use);
	
	new success = Lang_ReadFile(lang_file);
	if (success) {
		Log_Game("Lang: module init");
	} else {
		Log_Error("Lang: error: no such language file '"DATA_FILES_FOLDER "lang/%s"DATA_FILES_FORMAT"'", g_lang_use);
	}
	return 1;
}

stock Lang_LoadConfig(file_cfg)
{
	ini_getString(file_cfg, "lang_use", g_lang_use);
}

stock Lang_SaveConfig(file_cfg)
{
	ini_setString(file_cfg, "lang_use", g_lang_use);
}

stock Lang_ReadFile(filename[])
{
	new File:flang = fopen(filename, io_read);
	if (!flang) {
		return 0;
	}
	
	new len, sep_pos, string[MAX_LANG_STRING], varname[MAX_VAR_STRING];
	while (fread(flang, string, sizeof(string))) {
		len = strlen(string);
		if (len == 0 || string[0] == '#') {
			continue;
		}
		
		sep_pos = strfind(string, " = ", true);
		if (sep_pos != -1) {
			strmid(varname, string, 0, sep_pos);
			strmid(string, string, sep_pos + 3, len - 2);
			Lang_FixSpecialChar(string);
			Lang_SetText(varname, string);
		}
	}
	fclose(flang);
	return 1;
}

stock Lang_FixSpecialChar(string[MAX_LANG_STRING])
{
	for (new i = 0; string[i] != '\0'; i++) {
		if (string[i] != '\\') {
			continue;
		}
		switch (string[i+1]) {
			case 'n': {
				strdel(string, i, i + 2);
				strins(string, "\n", i);
			}
			case 't': {
				strdel(string, i, i + 2);
				strins(string, "\t", i);
			}
		}
	}
}

stock Lang_SetText(varname[], value[])
{
	if (!isnull(varname)) {
		setproperty(.value = bernstein(varname), .string = value);
	}
}

stock Lang_GetText(varname[])
{
	new result[MAX_STRING];
	if (!isnull(varname)) {
		getproperty(.value = bernstein(varname), .string = result);
		strunpack(result, result);
	}
	return result;
}

stock Lang_DeleteText(varname[])
{
	if (!isnull(varname)) {
		return deleteproperty(.value = bernstein(varname));
	}
	return 0;
}
