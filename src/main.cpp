#include "game.hpp"
#include <TGJGE.h>

#define FULL 1920, 1080, true
#define WIN 1366, 768, false

int main()
{
	TG_init("Social Battle Royale", WIN, 60);

	//init stuff
	srand(time(NULL));

	//stuff
	sbr::player player; 
	sbr::world world;
	std::vector<sbr::npc> npc;
	for(int i=0; i<NUM_NPCS; i++)
	{
		sbr::npc tmp_npc(world);
		npc.push_back(tmp_npc);
	}


	while(!TG_is_key_pressed(SDL_SCANCODE_ESCAPE))
	{
		//updates
		player.update();
		world.update(player);
		for(int i=0; i<NUM_NPCS; i++)
		{
			npc[i].update(player);
		}

		//render
		world.render(player);
		for(int i=0; i<NUM_NPCS; i++)
		{
			npc[i].render(player);
		}
		player.render();
		TG_flip(SEA_COLOR);
	}
	TG_quit();
	return 0;
}