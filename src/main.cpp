#include "game.hpp"
#include <TGJGE.h>

#define FULL 1920, 1080, true
#define WIN 1366, 768, false

int main()
{
	TG_init("Social Battle Royale", FULL, 60);

	//init stuff
	srand(time(NULL));

	//stuff
	sbr::player player; 
	sbr::world world;
	sbr::npc npc(world);
	sbr::npc npc2(world);
	sbr::npc npc3(world);
	sbr::npc npc4(world);


	while(!TG_is_key_pressed(SDL_SCANCODE_ESCAPE))
	{
		//updates
		player.update();
		world.update(player);


		//render
		world.render(player);
		npc.render(player);
		npc2.render(player);
		npc3.render(player);
		npc4.render(player);
		player.render();
		TG_flip(SEA_COLOR);
	}
	TG_quit();
	return 0;
}