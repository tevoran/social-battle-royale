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
	public:
		npc();
		~npc();
		void render(sbr::player& player);
	};
}

#endif