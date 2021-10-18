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

		//npc traits
		std::string name;
		int sex;
		bool introvert; //todo
		int sexuality; //todo
		bool depressed; //todo
		bool has_partner; //todo
		bool poor; //todo
		bool drunk; //todo
		float attractivity; //todo

		//relationships
		int character_id;


		//conversations
		bool current_conversation=false;

	public:
		npc(sbr::world& world);
		~npc();
		void render(sbr::player& player);
		void update(sbr::player& player, sbr::conversation& convo);

		//npc convo implementations
		void elias(sbr::conversation& convo);
	};
}

#endif