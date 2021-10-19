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
	if((rand()%10)>5)
	{
		grumpy=true;
	}

	//introvert or extrovert
	introvert=false;
	if((rand()%10)>5)
	{
		introvert=true;
	}

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
		//greeting=true;
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
		current_conversation=false;
		convo.active(current_conversation);
	}

	//the actual conversation code
	sbr::relationships& relationships=sbr::relationships::get();
	if(current_conversation)
	{
		do_conversation(convo, round);
	}
/*	if(current_conversation)
	{
		busy=false; //use the first available interaction

		//greeting
		//std::cout << greeting << std::endl;
		if(greeting && !greeting_active && round==0 && !busy)
		{
			//greeting
			busy=true;
			greeting_active=true;
			intro_active=true;
			std::string greeting_s("Hello, I am ");
			std::string complete=greeting_s+name;
			convo.add_line(complete);
			convo.add_line(std::string("press <SPACE> to continue"));
		}
		if(greeting && TG_is_key_pressed(SDL_SCANCODE_SPACE) && greeting_active)
		{
			greeting=false; //activate round 1
			intro_active=false;
			convo.clear();
		}

		//general activities
		if(drinking && !busy)
		{
			busy=true;
			if(!drinking_active)
			{
				drinking_active=true;
				//convo.clear();

			}
		}

		//round 1
		if(	round==0
			&& !busy)
		{
			busy=true;
			//intro
			if(relationships.get_status(player.character_id, character_id)
				> RELATIONSHIP_START)

			{
				if(!intro_active)
				{
					convo.add_line(std::string("It's nice to see you."));
					convo.add_line(std::string("The party seems quite cool so far."));
					convo.add_line(std::string("press <ENTER> for drinking with ") + name);
					convo.add_line(std::string("press <SPACE> for kissing with ") + name);
					relationships.change_status(player.character_id, character_id, 5);
					intro_active=true;
				}
				if(TG_is_key_pressed(SDL_SCANCODE_RETURN))
				{
					drinking=true;
				}
				if(TG_is_key_pressed(SDL_SCANCODE_SPACE))
				{
					//kissing=true;
				}
			}
			else
			{
				if(grumpy)
				{
					if(!intro_active)
					{
						intro_active=true;
						convo.add_line(std::string("But leave me alone."));
						relationships.change_status(player.character_id, character_id, -5);
					}
				}
				else
				{
					if(!intro_active)
					{
						convo.add_line(std::string("But who are you?"));
						convo.add_line(std::string("press <ENTER> to introduce yourself"));
						convo.add_line(std::string("press <SPACE> to ask ") + name);
						intro_active=true;
					}
				}
			}
		}
	}

	//clear all variables to reset the conversation but not its game effects
	else
	{
		greeting=false;
		greeting_active=false;
		intro_active=false;
		drinking=false;
		drinking_active=false;
	}
*/
}

void sbr::npc::do_conversation(sbr::conversation& convo, int round)
{
	//looking for first matching conversation entry
	for(int i=0; i<convo_element_list.size(); i++)
	{
		sbr::convo_element current_element=convo_element_list[i];

		if(	current_element.cond_round==round
			|| current_element.cond_round==CONVO_ELEMENT_CONDITION_IRRELEVANT)
		{
			convo.clear();
			convo.add_line(current_element.text1);
			convo.add_line(current_element.text2);
		}
	}
}

void sbr::npc::set_up_conversation_list()
{
	sbr::convo_element tmp_element(
		std::string("Hello, I am ") + name,
		std::string(" "),
		false,
		1,
		0,
		CONVO_ELEMENT_CONDITION_IRRELEVANT,
		CONVO_ELEMENT_CONDITION_IRRELEVANT,
		CONVO_ELEMENT_CONDITION_IRRELEVANT,
		CONVO_ELEMENT_CONDITION_IRRELEVANT,
		1,
		CONVO_ELEMENT_CONDITION_IRRELEVANT,
		CONVO_ELEMENT_CONDITION_IRRELEVANT,
		false,
		CONVO_ELEMENT_CONDITION_IRRELEVANT,
		std::string(" "),
		CONVO_ELEMENT_CONDITION_IRRELEVANT,
		std::string(" "),
		CONVO_ELEMENT_CONDITION_IRRELEVANT
		);
	
	convo_element_list.push_back(tmp_element);
}
