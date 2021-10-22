#include "game.hpp"


sbr::player::player(bool intro_toggle)
{
	object=TG_new_object(TILE_X, TILE_Y, PLAYER_SCREEN_POS_X, PLAYER_SCREEN_POS_Y, 16);
	tex=TG_new_texture("assets/PlayerComplete.png", false);
	TG_use_texture_object(object, tex);

	if(intro_toggle)
	{
		intro();
	}

	sbr::relationships& relationships=sbr::relationships::get();
	character_id=relationships.add_character();
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
			TG_start_animation_object(object, 1, 4, 175, 1);
		}
	}
}

sbr::player::~player()
{
	TG_destroy_texture(tex);
	TG_destroy_object(object);
}