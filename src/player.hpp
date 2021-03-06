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
		TG_texture *tex;
		bool animated=false;
	public:
		TG_object *object;
		
		float x=PLAYER_SCREEN_POS_X;
		float y=PLAYER_SCREEN_POS_Y;
		float dx=0;
		float dy=0;

		//player traits
		int sex=NPC_FEMALE;

		//relationships
		int character_id;
		void update();
		void render();
		player(bool intro_toggle);
		void intro();
		~player();
	};	
}

#endif