#ifndef CONVERSATION_HPP
#define CONVERSATION_HPP

namespace sbr
{
	class conversation
	{
	private:
		TG_object *win_obj;
		TG_texture *win_tex;
		bool active_convo=false;
		TG_font *text_regular=NULL;

		//active texts
		std::vector<TG_text*> active_texts;

	public:
		conversation();
		~conversation();
		void active(bool is_active);
		void add_line(std::string string);
		void clear();
		void render();
	};

	class convo_element
	{
	public:
		bool active_element;
		std::string text1; //first line shown
		std::string text2; //second line shown
		bool once;
		bool was_active=false;
		int ID;

		//conditions
		int cond_round;
		int cond_min_relationship_value;
		int cond_max_relationship_value;
		int cond_grumpy;
		int cond_drunk;

		//effects while using this element
		int relationship_value_delta;
		int grumpy;
		int drunk;

		//choices
		bool choices;
		int follow_up_ID; //if no choice then use the follow_up_ID
		//choice 1
		//use ENTER/RETURN key
		std::string text_choice1;
		int choice1_follow_up_ID;

		//choice 2
		//use SPACE key
		std::string text_choice2;
		int choice2_follow_up_ID;

		convo_element(){active_element=false;};
		convo_element(
			std::string text1_in,
			std::string text2_in,
			bool once_in,
			int ID_in,
			int cond_round_in,
			int cond_min_relationship_value_in,
			int cond_max_relationship_value_in,
			int cond_grumpy_in,
			int cond_drunk_in,
			int relationship_value_delta_in,
			int grumpy_in,
			int drunk_in,
			bool choices_in,
			int follow_up_ID_in,
			std::string text_choice1_in,
			int choice1_follow_up_ID_in,
			std::string text_choice2_in,
			int choice2_follow_up_ID_in)
		{
			active_element=true;
			text1=text1_in;
			text2=text2_in;
			once=once_in;
			ID=ID_in;
			cond_round=cond_round_in;
			cond_min_relationship_value=cond_min_relationship_value_in;
			cond_max_relationship_value=cond_max_relationship_value_in;
			cond_grumpy=cond_grumpy_in;
			cond_drunk=cond_drunk_in;
			choices=choices_in;
			follow_up_ID=follow_up_ID_in;
			text_choice1=text_choice1_in;
			choice1_follow_up_ID=choice1_follow_up_ID_in;
			text_choice2=text_choice2_in;
			choice2_follow_up_ID=choice2_follow_up_ID_in;
		};
	};
}

#endif