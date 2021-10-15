#include "game.hpp"
#include <TGJGE.h>


int main()
{
	TG_init("Social Battle Royale", 1366, 768, false, 60);

	//stuff
	sbr::player player; 
	sbr::world world;

	while(!TG_is_key_pressed(SDL_SCANCODE_ESCAPE))
	{
		player.update();
		world.update(player);

		world.render(player);
		player.render();
		TG_flip(SEA_COLOR);
	}
	TG_quit();
	return 0;
}