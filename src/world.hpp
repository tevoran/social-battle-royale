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
		int tile_block[WORLD_SIZE_X][WORLD_SIZE_Y];
		TG_texture *world_tex;
		TG_texture *wallMiddle_tex;
	public:
		void update(sbr::player& player);
		void render(sbr::player& player);

		//tile blocking mechanism
		bool is_free(int x, int y);
		void set_block(int x, int y);
		void set_free(int x, int y);
		world();
		~world();
	};
}

#endif