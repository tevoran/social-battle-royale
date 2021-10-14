#include "game.hpp"
#include <TGJGE.h>


int main()
{
	TG_init("Social Battle Royale", 1366, 768, false, 60);

	//stuff
	sbr::player player; 


	while(!TG_is_key_pressed(SDL_SCANCODE_ESCAPE))
	{
		player.update();
		player.render();
		TG_flip(0,0,0);
	}
	TG_quit();
	return 0;
}