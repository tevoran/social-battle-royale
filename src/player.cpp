#include "game.hpp"

sbr::player::player()
{
	object=TG_new_object(TILE_X, TILE_Y, x, y, 3);
	tex=TG_new_texture("assets/player.png", false);
	TG_use_texture_object(object, tex);
}

void sbr::player::render()
{
	TG_render_object(object);
}

void sbr::player::update()
{
	//resetting player speed
	dx=0;
	dy=0;

	//up
	if(TG_is_key_pressed(SDL_SCANCODE_W))
	{
		dy=PLAYER_SPEED * (0.001)*TG_delta_time();
	}
	//down
	if(TG_is_key_pressed(SDL_SCANCODE_S))
	{
		dy=-PLAYER_SPEED * (0.001)*TG_delta_time();
	}
	//right
	if(TG_is_key_pressed(SDL_SCANCODE_D))
	{
		dx=PLAYER_SPEED * (0.001)*TG_delta_time();
	}
	//left
	if(TG_is_key_pressed(SDL_SCANCODE_A))
	{
		dx=-PLAYER_SPEED * (0.001)*TG_delta_time();
	}

	if(	!TG_is_key_pressed(SDL_SCANCODE_W) &&
		!TG_is_key_pressed(SDL_SCANCODE_S) &&
		!TG_is_key_pressed(SDL_SCANCODE_D) &&
		!TG_is_key_pressed(SDL_SCANCODE_A))
	{
		TG_stop_animation_object(object);
		animated=false;
	}
	
	//normalize the speed
	float dxdy = sqrt(dx*dx+dy*dy);
	if(dxdy>0)
	{
		dx=(dx*PLAYER_SPEED*(0.001)*TG_delta_time())/dxdy;
		dy=(dy*PLAYER_SPEED*(0.001)*TG_delta_time())/dxdy;
		x+=dx;
		y+=dy;

		if(!animated)
		{
			animated=true;
			TG_start_animation_object(object, 1, 3, 200, 1);
		}
		TG_set_position_object(object, x, y);
	}
}

sbr::player::~player()
{
	TG_destroy_texture(tex);
	TG_destroy_object(object);
}