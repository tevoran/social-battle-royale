#ifndef WORLD_HPP
#define WORLD_HPP
#include "game.hpp"

namespace sbr
{
	class world
	{
	private:
		float pos_x=0;
		float pos_y=0;
		TG_object *tile[WORLD_SIZE_X][WORLD_SIZE_Y];
		TG_texture *world_tex;
	public:
		void render(sbr::player& player);
		world();
		~world();
	};
}

#endif