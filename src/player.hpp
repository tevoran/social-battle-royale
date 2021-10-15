#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <TGJGE.h>
#include "game.hpp"


namespace sbr
{
	//player
	class player
	{
	private:
		TG_object *object;
		TG_texture *tex;
		bool animated=false;
		float dx=0;
		float dy=0;

	public:
		float x=PLAYER_SCREEN_POS_X;
		float y=PLAYER_SCREEN_POS_Y;
		
		void update();
		void render();
		player();
		~player();
	};	
}

#endif