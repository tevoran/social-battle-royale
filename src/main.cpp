#include "game.hpp"
#include <TGJGE.h>

#define FULL 1920, 1080, true
#define WIN 1366, 768, false

#define INTRO true


int main()
{
	TG_init("Social Battle Royale", FULL, 60);
	TG_show_cursor(false);
	
	//init stuff
	srand(time(NULL));

	//stuff
	int round=0;
	sbr::player player(INTRO);
	sbr::world world;
	std::vector<sbr::npc> npc;
	for(int i=0; i<NUM_NPCS; i++)
	{
		sbr::npc tmp_npc(world);
		npc.push_back(tmp_npc);
	}
	sbr::conversation convo;


	//npc sprite
	// TG_object *test1=TG_new_object(TILE_X, TILE_Y, 0.05, 0.05, 1);
	// TG_texture *tex1=TG_new_texture("assets/Player1.png", false);
	// TG_use_texture_object(test1, tex1);



	while(!TG_is_key_pressed(SDL_SCANCODE_ESCAPE))
	{
		//updates
		player.update();
		world.update(player);
		for(int i=0; i<NUM_NPCS; i++)
		{
			npc[i].update(player, convo, round);
		}

		//render
		world.render(player);
		player.render();
		for(int i=0; i<NUM_NPCS; i++)
		{
			npc[i].render(player);
		}
		convo.render();
		// TG_render_object(test1);
		TG_new_frame(SEA_COLOR);
	}
	TG_quit();
	return 0;
}