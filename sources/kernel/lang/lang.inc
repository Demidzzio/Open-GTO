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

#define _(%0) lang_GetText(#%0)

static lang_Use[16] = LANG_USE;

stock lang_OnGameModeInit()
{
	new lang_file[MAX_STRING];
	format(lang_file, sizeof(lang_file), DATA_FILES_FOLDER "lang/%s"DATA_FILES_FORMAT, lang_Use);
	
	new success = lang_ReadFile(lang_file);
	if (success) {
		log_Game("Lang: module init");
	} else {
		log_Error("Lang: error: no such language file '"DATA_FILES_FOLDER "lang/%s"DATA_FILES_FORMAT"'", lang_Use);
	}
	return 1;
}

stock lang_LoadConfig(file_cfg)
{
	ini_getString(file_cfg, "lang_use", lang_Use);
	return 1;
}

stock lang_SaveConfig(file_cfg)
{
	ini_setString(file_cfg, "lang_use", lang_Use);
	return 1;
}

stock lang_ReadFile(filename[])
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
			lang_FixSpecialChar(string);
			lang_SetText(varname, string);
		}
	}
	fclose(flang);
	return 1;
}

stock lang_FixSpecialChar(string[MAX_LANG_STRING])
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

stock lang_SetText(varname[], value[])
{
	if (!isnull(varname)) {
		setproperty(.value = bernstein(varname), .string = value);
	}
}

stock lang_GetText(varname[])
{
	new result[MAX_STRING];
	if (!isnull(varname)) {
		getproperty(.value = bernstein(varname), .string = result);
		strunpack(result, result);
	}
	return result;
}

stock lang_DeleteText(varname[])
{
	if (!isnull(varname)) {
		return deleteproperty(.value = bernstein(varname));
	}
	return 0;
}
