#include "game.hpp"
#include <TGJGE.h>

#define NUM_DIF_TILES 9

sbr::world::world()
{
	world_tex=TG_new_texture("assets/world_tiles.png", false);

	for(int ix=0; ix<WORLD_SIZE_X; ix++)
	{
		for(int iy=0; iy<WORLD_SIZE_Y; iy++)
		{
			tile[iy][ix]=TG_new_object(
				TILE_X,
				TILE_Y,
				TILE_X*ix,
				TILE_Y*iy,
				NUM_DIF_TILES);
			TG_use_texture_object(tile[iy][ix], world_tex);
			
			//using a mid tile as default
			TG_start_animation_object(
				tile[iy][ix],
				9, 
				9, 
				INT_MAX,
				false);

			//left bottom tile
			if(ix==0 && iy==0)
			{
				TG_start_animation_object(
					tile[iy][ix],
					8, 
					8, 
					INT_MAX,
					false);
			}
			//left tile
			if(ix==0 && iy!=0)
			{
				TG_start_animation_object(
					tile[iy][ix],
					1, 
					1, 
					INT_MAX,
					false);
			}
			//left top tile
			if(ix==0 && iy==WORLD_SIZE_Y-1)
			{
				TG_start_animation_object(
					tile[iy][ix],
					2, 
					2, 
					INT_MAX,
					false);
			}
			//top tile
			if(ix!=0 && iy==WORLD_SIZE_Y-1)
			{
				TG_start_animation_object(
					tile[iy][ix],
					3, 
					3, 
					INT_MAX,
					false);
			}
			//right top tile
			if(ix==WORLD_SIZE_X-1 && iy==WORLD_SIZE_Y-1)
			{
				TG_start_animation_object(
					tile[iy][ix],
					4, 
					4, 
					INT_MAX,
					false);
			}
			//right tile
			if(ix==WORLD_SIZE_X-1 && iy!=WORLD_SIZE_Y-1)
			{
				TG_start_animation_object(
					tile[iy][ix],
					5, 
					5, 
					INT_MAX,
					false);
			}
			//right bottom tile
			if(ix==WORLD_SIZE_X-1 && iy==0)
			{
				TG_start_animation_object(
					tile[iy][ix],
					6, 
					6, 
					INT_MAX,
					false);
			}
			//bottom tile
			if(ix!=WORLD_SIZE_X-1 && ix!=0 && iy==0)
			{
				TG_start_animation_object(
					tile[iy][ix],
					7, 
					7, 
					INT_MAX,
					false);
			}
		}
	}
}

void sbr::world::render(sbr::player& player)
{
	pos_x=-player.x;
	pos_y=-player.y;
	for(int ix=0; ix<WORLD_SIZE_X; ix++)
	{
		for(int iy=0; iy<WORLD_SIZE_Y; iy++)
		{
			TG_set_position_object(
				tile[iy][ix],
				pos_x+TILE_X*ix,
				pos_y+TILE_Y*iy);
			TG_render_object(tile[iy][ix]);
		}
	}
}

void sbr::world::update(sbr::player& player)
{
	//don't let player move outside the world
	if(player.x<(-PLAYER_SCREEN_POS_X))
	{
		player.x=-PLAYER_SCREEN_POS_X;
	}
	if(player.x>((WORLD_SIZE_X-1)*TILE_X-PLAYER_SCREEN_POS_X))
	{
		player.x=(WORLD_SIZE_X-1)*TILE_X-PLAYER_SCREEN_POS_X;
	}
	if(player.y<(-PLAYER_SCREEN_POS_Y))
	{
		player.y=-PLAYER_SCREEN_POS_Y;
	}
	if(player.y>((WORLD_SIZE_Y-1)*TILE_Y-PLAYER_SCREEN_POS_Y))
	{
		player.y=(WORLD_SIZE_Y-1)*TILE_Y-PLAYER_SCREEN_POS_Y;
	}
}

sbr::world::~world()
{
	TG_destroy_texture(world_tex);

	for(int ix=0; ix<WORLD_SIZE_X; ix++)
	{
		for(int iy=0; iy<WORLD_SIZE_Y; iy++)
		{
			TG_destroy_object(tile[iy][ix]);
		}
	}
}