/*
	
	About: player
	Author: ziggi
	
*/

stock player_LoadClass()
{
	for(new i = 0; i <= 299; i++) {
		switch (i) {
			case SKINS_IGNORE: {}
			default: AddPlayerClass(i, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
		}
	}
	log_Game(_(PLAYER_CLASSES_INIT));
}
