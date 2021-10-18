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
		bool grumpy;
		bool drunk=false;


		bool introvert; //todo
		int sexuality; //todo
		bool depressed; //todo
		bool has_partner; //todo
		bool poor; //todo
		float attractivity; //todo

		//conversations
		bool current_conversation=false;

		bool greeting=false;
		bool greeting_active=false;
		bool intro_active=false;
		bool drinking=false;
		bool drinking_active=false;
	public:
		//relationships
		int character_id;

		npc(sbr::world& world);
		~npc();
		void render(sbr::player& player);
		void update(sbr::player& player, sbr::conversation& convo, int round);


	};
}

#endif