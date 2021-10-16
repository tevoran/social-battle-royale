#ifndef NPC_HPP
#define NPC_HPP

#include "game.hpp"

namespace sbr
{
	class npc
	{
	private:
		TG_object *object;
		TG_texture *tex;
		float pos_x;
		float pos_y;
	public:
		npc(sbr::world& world);
		~npc();
		void render(sbr::player& player);
		void update(sbr::player& player);
	};
}

#endif