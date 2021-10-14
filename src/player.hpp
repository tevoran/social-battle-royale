#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <TGJGE.h>

namespace sbr
{
	//player
	class player
	{
	private:
		TG_object *object;
		TG_texture *tex;
		bool animated=false;
	public:
		float x=0.45;
		float dx=0;
		float y=0.45;
		float dy=0;
		void update();
		void render();
		player();
		~player();
	};	
}

#endif