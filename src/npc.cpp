#include "game.hpp"
#include "npc.hpp"


sbr::npc::npc()
{
	object=TG_new_object(TILE_X, TILE_Y, 0.0, 0.0, 1);
	tex=TG_new_texture("assets/npc.png", false);
	TG_use_texture_object(object, tex);
}

sbr::npc::~npc()
{
	TG_destroy_object(object);
	TG_destroy_texture(tex);
}

void sbr::npc::render(sbr::player& player)
{
	TG_set_position_object(object, -player.x, -player.y);
	TG_render_object(object);
}
