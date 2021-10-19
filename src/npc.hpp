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
		bool introvert;

		int sexuality; //todo
		bool depressed; //todo
		bool has_partner; //todo
		bool poor; //todo
		float attractivity; //todo

		//conversations
		bool current_conversation=false;
		std::vector<sbr::convo_element> convo_element_list;
		sbr::convo_element current_element; //conversation is at this element right now


		void set_up_conversation_list();
		void do_conversation(sbr::conversation& convo, sbr::player& player, int round);
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