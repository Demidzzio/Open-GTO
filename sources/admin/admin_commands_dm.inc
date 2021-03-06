//
// Created: 05.11.06
// Aurthor: Iain Gilbert
//

#if defined _admin_commands_dm_included
	#endinput
#endif

#define _admin_commands_dm_included
#pragma library admin_commands_dm


stock AdminDM_OnPlayerCommandText(playerid, text[]) // process player commands
{
	if (!IsPlayerAdm(playerid)) return 0;
	new cmd[20], idx;
	cmd = strcharsplit(text, idx, ' ');
	if (!strcmp(cmd, "/dm", true))
	{
		cmd = strcharsplit(text, idx, ' ');
		if (strlen(cmd) == 0) return 0;
		if (!strcmp(cmd, "start", true))
		{
			new dmid = strval(strcharsplit(text, idx, ' '));
			
			if (dmid == 0 || dmid >= MAX_DM)
			{
				return SendClientMessage(playerid, COLOUR_RED, lang_texts[14][22]);
			}
			
			switch (DeathmatchStats[dmid][dm_state])
			{
				case DM_STATE_DISABLED:
				{
					return SendClientMessage(playerid, COLOUR_RED, lang_texts[14][23]);
				}
				case DM_STATE_ACTIVE:
				{
					return SendClientMessage(playerid, COLOUR_RED, lang_texts[14][24]);
				}
				case DM_STATE_LINEUP:
				{
					DeathmatchStats[dmid][dm_timer] = 0;
					StartDMCountdown(dmid);
					return 1;
				}
				case DM_STATE_SLEEPING:
				{
					DeathmatchStats[dmid][dm_timer] = 0;
					StartDMLineup(dmid);
					return 1;
				}
			}
			return 1;
		}
	}
	return 0;
}
