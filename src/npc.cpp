#include "game.hpp"
#include "npc.hpp"

#define NUM_NAMES 20

std::string npc_names[]=
{
	"Elias",
	"Abraham",
	"Alberta",
	"Alexa",
	"Nick",
	"Laura",
	"Lara",
	"John",
	"Anna",
	"Oliver",
	"Luna",
	"Owen",
	"Amelia",
	"Felix",
	"Olivia",
	"Ophelia",
	"Isaac",
	"Sophia",
	"Athena",
	"Arthur",
};

sbr::npc::npc(sbr::world& world)
{
	//npc sprite
	object=TG_new_object(TILE_X, TILE_Y, 0.0, 0.0, 1);
	tex=TG_new_texture("assets/npc.png", false);
	TG_use_texture_object(object, tex);

	//set NPC to random location
	int tile_x=0;
	int tile_y=0;
	do
	{
		tile_x=rand()%WORLD_SIZE_X;
		tile_y=rand()%WORLD_SIZE_Y;
	}while(!world.is_free(tile_x, tile_y));
	world.set_block(tile_x, tile_y);
	pos_x=TILE_X*tile_x;
	pos_y=TILE_Y*tile_y;

	//determining traits
	int random_name=rand()%NUM_NAMES;
	name=npc_names[random_name];
	std::cout << "NPC's name is " << name << std::endl;

	//determining sex
	//if name ends with 'a' then the NPC is female
	if(name.c_str()[name.length()-1]=='a')
	{
		sex=NPC_FEMALE;
		std::cout << "female\n";
	}
	else
	{
		sex=NPC_MALE;
		std::cout << "male\n";
	}

	//grumpy
	grumpy=false;
	if((rand()%9)>5)
	{
		grumpy=true;
	}

	//introvert or extrovert
	introvert=false;
	if((rand()%12)>5)
	{
		introvert=true;
	}
	std::cout << "NPC is introvert " << introvert << std::endl;

	//setting up relationship network
	sbr::relationships& relationships=sbr::relationships::get();
	character_id=relationships.add_character();

	//setting up conversation database for the NPC
	set_up_conversation_list();
}

sbr::npc::~npc()
{
	/*comment causes memory leaks but the fix seems a bit too complicated for a jam*/
	//TG_destroy_object(object);
	//TG_destroy_texture(tex);
}

void sbr::npc::render(sbr::player& player)
{
	TG_set_position_object(object, pos_x-player.x, pos_y-player.y);
	TG_render_object(object);
}

void sbr::npc::update(sbr::player& player, sbr::conversation& convo, int round)
{
	//collision starts a conversation
	//don't let player move into the npc
	float tmp_player_x=player.x;
	float tmp_player_y=player.y;
	tmp_player_x+=player.dx;
	tmp_player_y+=player.dy;
	float tmp_npc_x=pos_x-tmp_player_x;
	float tmp_npc_y=pos_y-tmp_player_y;
	TG_set_position_object(object, tmp_npc_x, tmp_npc_y);
	if(TG_is_colliding(object, player.object))
	{
		player.x-=player.dx;
		player.y-=player.dy;
		current_conversation=true;
		convo.active(current_conversation);
	}
	TG_set_position_object(object, pos_x, pos_y);

	//ending a conversation if distance is too far
	float a=PLAYER_SCREEN_POS_X-(pos_x-player.x);
	float b=PLAYER_SCREEN_POS_Y-(pos_y-player.y);
	float distance=sqrt(a*a+b*b);
	if(distance>CONVO_END_RADIUS && current_conversation==true)
	{
		current_element.active_element=false;
		current_conversation=false;
		convo.active(current_conversation);
	}

	//the actual conversation code
	sbr::relationships& relationships=sbr::relationships::get();
	if(current_conversation)
	{
		do_conversation(convo, player, round);
	}
}

void sbr::npc::do_conversation(sbr::conversation& convo, sbr::player& player, int round)
{
	sbr::relationships& relationships=sbr::relationships::get();

	//looking for first matching conversation entry
	if(current_element.active_element==false)
	{
		//going from very specific to least specific
		for(int i=0; i<convo_element_list.size(); i++)
		{
			//use round specific elements
			if( convo_element_list[i].cond_round==round)
			{
				//introvert
				if(	convo_element_list[i].cond_introvert==true
					&& introvert==true)
				{
					current_element=convo_element_list[i];
				}
				//grumpy
				if(	convo_element_list[i].cond_grumpy==true
					&& grumpy==true)
				{
					current_element=convo_element_list[i];
					break;
				}
			}

			//use non round specific elements
			if( convo_element_list[i].cond_round==CONVO_ELEMENT_CONDITION_IRRELEVANT)
			{

			}

		}

		//if no element has been found, simply display the first one
		if(current_element.active_element==false)
		{
			current_element=convo_element_list[0];
		}

		//update effects that are caused by the element
		if(current_element.relationship_value_delta!=CONVO_ELEMENT_CONDITION_IRRELEVANT)
		{
			relationships.change_status(
				player.character_id, 
				character_id, 
				current_element.relationship_value_delta);
		}
	}

	//if active convo element
	//then display element and wait for player choice
	else
	{
		//display
		convo.clear();
		convo.add_line(current_element.text1);
		convo.add_line(current_element.text2);
		if(current_element.choices)
		{
			convo.add_line(current_element.text_choice1);
			convo.add_line(current_element.text_choice2);
		}
		else
		{
			convo.add_line("press <SPACE> to continue");
		}

		//wait for input
		static bool key_down=false;
		if(TG_is_key_pressed(SDL_SCANCODE_SPACE) && !current_element.choices && !key_down)
		{
			key_down=true;
			//looking for follow up entry
			for(int i=0; i<convo_element_list.size(); i++)
			{
				if(convo_element_list[i].ID==current_element.follow_up_ID)
				{
					current_element=convo_element_list[i];
					break;
				}
			}
		}

		if(TG_is_key_pressed(SDL_SCANCODE_RETURN) && current_element.choices && !key_down)
		{
			key_down=true;
			//looking for follow up entry
			for(int i=0; i<convo_element_list.size(); i++)
			{
				if(convo_element_list[i].ID==current_element.choice1_follow_up_ID)
				{
					current_element=convo_element_list[i];
					break;
				}
			}
		}

		if(TG_is_key_pressed(SDL_SCANCODE_SPACE) && current_element.choices && !key_down)
		{
			key_down=true;
			//looking for follow up entry
			for(int i=0; i<convo_element_list.size(); i++)
			{
				if(convo_element_list[i].ID==current_element.choice2_follow_up_ID)
				{
					current_element=convo_element_list[i];
					break;
				}
			}
		}

		//reset key_down
		if(	!TG_is_key_pressed(SDL_SCANCODE_SPACE) &&
			!TG_is_key_pressed(SDL_SCANCODE_RETURN))
		{
			key_down=false;
		}
	}

}

void sbr::npc::set_up_conversation_list()
{
	#define REGULAR_GREETING 1
	#define INTROVERT_GREETING 2
	#define GRUMPY_GREETING 3
	#define END 4
	#define FUCK 5
	//greeting1
	sbr::convo_element greeting1;
		greeting1.active_element=true;
		greeting1.text1=std::string("Hello, I am ") + name;
		greeting1.text2=std::string("Nice to see you here.");
		greeting1.relationship_value_delta=2;
		greeting1.ID=REGULAR_GREETING;
		greeting1.follow_up_ID=END;
	convo_element_list.push_back(greeting1);

	//greeting introvert
	sbr::convo_element greeting_introvert;
		greeting_introvert.active_element=true;
		greeting_introvert.text1=std::string("Hello, I am ") + name;
		greeting_introvert.text2=std::string("I am not sure if I will like this party.");
		greeting_introvert.cond_introvert=true;
		greeting_introvert.cond_round=0;
		greeting_introvert.ID=INTROVERT_GREETING;
		greeting_introvert.follow_up_ID=END;
	convo_element_list.push_back(greeting_introvert);

	//greeting grumpy
	sbr::convo_element greeting_grumpy;
		greeting_grumpy.active_element=true;
		greeting_grumpy.text1=std::string("I am ") + name;
		greeting_grumpy.text2=std::string("But leave me alone.");
		greeting_grumpy.cond_round=0;
		greeting_grumpy.cond_grumpy=true;
		greeting_grumpy.relationship_value_delta=-2;
		greeting_grumpy.choices=true;
		greeting_grumpy.ID=GRUMPY_GREETING;
		greeting_grumpy.text_choice1=std::string("press <RETURN> for insulting ") + name;
		greeting_grumpy.choice1_follow_up_ID=FUCK;
		greeting_grumpy.text_choice2=std::string("press <SPACE> for calming down ") + name;
		greeting_grumpy.choice2_follow_up_ID=END;
	convo_element_list.push_back(greeting_grumpy);

	//end response
	sbr::convo_element end;
		end.active_element=true;
		end.text1=std::string("See you.");
		end.ID=END;
		end.follow_up_ID=END; //repeat the response
	convo_element_list.push_back(end);	

	//fuck you
	sbr::convo_element fuck;
		fuck.active_element=true;
		fuck.text1=std::string("Fuck you!");
		fuck.text2=std::string("Leave me alone!");
		fuck.relationship_value_delta=-5;
		fuck.ID=FUCK;
		fuck.follow_up_ID=FUCK; //repeat the response
	convo_element_list.push_back(fuck);
}
