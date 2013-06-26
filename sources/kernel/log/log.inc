/*
	
	About: log functions
	Author: ziggi

*/

#if defined _log_included
	#endinput
#endif

#define _log_included
#pragma library log


enum {
	LOG_Game = 0,
	LOG_User,
	LOG_Error,
	LOG_Debug,
}

new log_dir[][] = {
	DATA_FILES_FOLDER "log/game/",
	DATA_FILES_FOLDER "log/user/",
	DATA_FILES_FOLDER "log/error/",
	DATA_FILES_FOLDER "log/debug/"
};

static
	bool:log_game_enabled = LOG_GAME_ENABLED,
	bool:log_user_enabled = LOG_USER_ENABLED,
	bool:log_error_enabled = LOG_ERROR_ENABLED,
	bool:log_debug_enabled = LOG_DEBUG_ENABLED;


stock log_OnGameModeInit()
{
	log_Game(_(LOG_INIT));
}

stock log_LoadConfig(file_cfg)
{
	ini_getInteger(file_cfg, "log_game_enabled", log_game_enabled);
	ini_getInteger(file_cfg, "log_user_enabled", log_user_enabled);
	ini_getInteger(file_cfg, "log_error_enabled", log_error_enabled);
	ini_getInteger(file_cfg, "log_debug_enabled", log_debug_enabled);
	return 1;
}

stock log_SaveConfig(file_cfg)
{
	ini_setInteger(file_cfg, "log_game_enabled", log_game_enabled);
	ini_setInteger(file_cfg, "log_user_enabled", log_user_enabled);
	ini_setInteger(file_cfg, "log_error_enabled", log_error_enabled);
	ini_setInteger(file_cfg, "log_debug_enabled", log_debug_enabled);
	return 1;
}

stock log_Write(log, string[])
{
	// get log file path
	new file_path[MAX_STRING], y, m, d;
	getdate(y, m, d);
	format(file_path, sizeof(file_path), "%s%04d-%02d-%02d.log", log_dir[log], y, m, d);
	
	// make string to write
	new line_string[MAX_STRING + 32], h, s;
	gettime(h, m, s);
	format(line_string, sizeof(line_string), "[%02d:%02d:%02d] %s\n", h, m, s, string);
	
	// write string in log
	new File:file_log = fopen(file_path, io_append);
	if (!file_log) {
		printf(_(LOG_ERROR_OPEN), file_path);
		return 0;
	}
	
	for (new i = 0, len = strlen(line_string); i < len; i++) {
		fputchar(file_log, line_string[i], false);
	}
	
	fclose(file_log);
	return 1;
}


#define BYTES_PER_CELL			4

stock log_Game(fstring[], {Float, _}:...)
{
	if (!log_game_enabled) {
		return 0;
	}
	
	static const STATIC_ARGS = 1;
	new n = (numargs() - STATIC_ARGS) * BYTES_PER_CELL;
	if (n) {
		new message[144], arg_start, arg_end;
		#emit CONST.alt			fstring
		#emit LCTRL				5
		#emit ADD
		#emit STOR.S.pri		arg_start

		#emit LOAD.S.alt		n
		#emit ADD
		#emit STOR.S.pri		arg_end
		do {
			#emit LOAD.I
			#emit PUSH.pri
			arg_end -= BYTES_PER_CELL;
			#emit LOAD.S.pri	arg_end
		} while(arg_end > arg_start);

		#emit PUSH.S			fstring
		#emit PUSH.C			144
		#emit PUSH.ADR			message

		n += BYTES_PER_CELL * 3;
		#emit PUSH.S			n
		#emit SYSREQ.C			format

		n += BYTES_PER_CELL;
		#emit LCTRL				4
		#emit LOAD.S.alt		n
		#emit ADD
		#emit SCTRL				4
		
	#if defined LOG_PRINTING
		printf(message);
	#endif
		log_Write(LOG_Game, message);
	} else {
	#if defined LOG_PRINTING
		printf(fstring);
	#endif
		log_Write(LOG_Game, fstring);
	}
	return 1;
}

stock log_User(fstring[], {Float, _}:...)
{
	if (!log_user_enabled) {
		return 0;
	}
	
	static const STATIC_ARGS = 1;
	new n = (numargs() - STATIC_ARGS) * BYTES_PER_CELL;
	if (n) {
		new message[144], arg_start, arg_end;
		#emit CONST.alt			fstring
		#emit LCTRL				5
		#emit ADD
		#emit STOR.S.pri		arg_start

		#emit LOAD.S.alt		n
		#emit ADD
		#emit STOR.S.pri		arg_end
		do {
			#emit LOAD.I
			#emit PUSH.pri
			arg_end -= BYTES_PER_CELL;
			#emit LOAD.S.pri	arg_end
		} while(arg_end > arg_start);

		#emit PUSH.S			fstring
		#emit PUSH.C			144
		#emit PUSH.ADR			message

		n += BYTES_PER_CELL * 3;
		#emit PUSH.S			n
		#emit SYSREQ.C			format

		n += BYTES_PER_CELL;
		#emit LCTRL				4
		#emit LOAD.S.alt		n
		#emit ADD
		#emit SCTRL				4
		
	#if defined LOG_PRINTING
		printf(message);
	#endif
		log_Write(LOG_User, message);
	} else {
	#if defined LOG_PRINTING
		printf(fstring);
	#endif
		log_Write(LOG_User, fstring);
	}
	return 1;
}

stock log_Error(fstring[], {Float, _}:...)
{
	if (!log_error_enabled) {
		return 0;
	}
	
	static const STATIC_ARGS = 1;
	new n = (numargs() - STATIC_ARGS) * BYTES_PER_CELL;
	if (n) {
		new message[144], arg_start, arg_end;
		#emit CONST.alt			fstring
		#emit LCTRL				5
		#emit ADD
		#emit STOR.S.pri		arg_start

		#emit LOAD.S.alt		n
		#emit ADD
		#emit STOR.S.pri		arg_end
		do {
			#emit LOAD.I
			#emit PUSH.pri
			arg_end -= BYTES_PER_CELL;
			#emit LOAD.S.pri	arg_end
		} while(arg_end > arg_start);

		#emit PUSH.S			fstring
		#emit PUSH.C			144
		#emit PUSH.ADR			message

		n += BYTES_PER_CELL * 3;
		#emit PUSH.S			n
		#emit SYSREQ.C			format

		n += BYTES_PER_CELL;
		#emit LCTRL				4
		#emit LOAD.S.alt		n
		#emit ADD
		#emit SCTRL				4
		
	#if defined LOG_PRINTING
		printf(message);
	#endif
		log_Write(LOG_Error, message);
		if (log_game_enabled) {
			log_Write(LOG_Game, message);
		}
	} else {
	#if defined LOG_PRINTING
		printf(fstring);
	#endif
		log_Write(LOG_Error, fstring);
		if (log_game_enabled) {
			log_Write(LOG_Game, fstring);
		}
	}
	return 1;
}

stock log_Debug(fstring[], {Float, _}:...)
{
	if (!log_debug_enabled) {
		return 0;
	}
	
	static const STATIC_ARGS = 1;
	new n = (numargs() - STATIC_ARGS) * BYTES_PER_CELL;
	if (n) {
		new message[144], arg_start, arg_end;
		#emit CONST.alt			fstring
		#emit LCTRL				5
		#emit ADD
		#emit STOR.S.pri		arg_start

		#emit LOAD.S.alt		n
		#emit ADD
		#emit STOR.S.pri		arg_end
		do {
			#emit LOAD.I
			#emit PUSH.pri
			arg_end -= BYTES_PER_CELL;
			#emit LOAD.S.pri	arg_end
		} while(arg_end > arg_start);

		#emit PUSH.S			fstring
		#emit PUSH.C			144
		#emit PUSH.ADR			message

		n += BYTES_PER_CELL * 3;
		#emit PUSH.S			n
		#emit SYSREQ.C			format

		n += BYTES_PER_CELL;
		#emit LCTRL				4
		#emit LOAD.S.alt		n
		#emit ADD
		#emit SCTRL				4
		
	#if defined LOG_PRINTING
		printf(message);
	#endif
		log_Write(LOG_Debug, message);
	} else {
	#if defined LOG_PRINTING
		printf(fstring);
	#endif
		log_Write(LOG_Debug, fstring);
	}
	return 1;
}
