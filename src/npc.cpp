#include "game.hpp"
#include "npc.hpp"


sbr::npc::npc(sbr::world& world)
{
	object=TG_new_object(TILE_X, TILE_Y, 0.0, 0.0, 1);
	tex=TG_new_texture("assets/npc.png", false);
	TG_use_texture_object(object, tex);

	//set NPC to random location
	int tile_x=0;
	int tile_y=0;
	do
	{
		tile_x=rand()%WORLD_SIZE_X;
		tile_y=rand()%WORLD_SIZE_Y;
	}while(!world.is_free(tile_x, tile_y));
	world.set_block(tile_x, tile_y);
	std::cout << tile_x << "x" << tile_y << std::endl;
	pos_x=TILE_X*tile_x;
	pos_y=TILE_Y*tile_y;
}

sbr::npc::~npc()
{
	/*comment causes memory leaks but the fix seems a bit too complicated for a jam*/
	//TG_destroy_object(object);
	//TG_destroy_texture(tex);
}

void sbr::npc::render(sbr::player& player)
{
	TG_set_position_object(object, pos_x-player.x, pos_y-player.y);
	TG_render_object(object);
}

void sbr::npc::update(sbr::player& player)
{
	//don't let player move into the npc
	float tmp_player_x=player.x;
	float tmp_player_y=player.y;
	tmp_player_x+=player.dx;
	tmp_player_y+=player.dy;
	float tmp_npc_x=pos_x-tmp_player_x;
	float tmp_npc_y=pos_y-tmp_player_y;
	TG_set_position_object(object, tmp_npc_x, tmp_npc_y);
	if(TG_is_colliding(object, player.object))
	{
		player.x-=player.dx;
		player.y-=player.dy;
	}
	TG_set_position_object(object, pos_x, pos_y);

}