#ifndef NPC_RELATIONSHIP_HPP
#define NPC_RELATIONSHIP_HPP

#include <game.hpp>



//all characters should join the game before it starts
//this is a big assumption in the code

namespace sbr
{
	class relationships
	{
	private:
		relationships(){};
		int num_participants=0;
		int num_participants_alive=0;

		std::vector<std::vector<int>> relationship_array; //value is between 0 and 100
	public:
		~relationships(){};
		relationships(const relationships&) = delete; //remove copyconstructor
		static relationships& get(){static relationships instance; return instance;};

		int add_character();

		//interactions
		//returns the relationship value between the current and the other character
		int get_status(int current_character_id, int other_character_id);
		void set_status(int current_character_id, int other_character_id, int new_status_value);
		void change_status(int current_character_id, int other_character_id, int delta_value);
	};
}

#endif