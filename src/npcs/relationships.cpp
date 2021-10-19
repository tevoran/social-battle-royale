#include <game.hpp>


int sbr::relationships::add_character()
{
	int character_id=num_participants;
	std::cout << "creating character " << character_id << " in relationship network.\n";

	num_participants++;
	num_participants_alive++;

	//create all the relations
	std::vector<int> character_relations;
	for(int i=0; i<num_participants; i++)
	{
		//create random relationship start value
		int value=
			RELATIONSHIP_START
			-RELATIONSHIP_VARIANCE
			+rand()%(2*RELATIONSHIP_VARIANCE);
		if(i==character_id)
		{
			value=0;
		}
		character_relations.emplace_back(value);
	}

	//the syntax of the 2D vector is
	//relationship_array[character_id][character_relations]
	relationship_array.emplace_back(character_relations);

	//add new relationship to existing characters
	int value=RELATIONSHIP_START;
	for(int i=0; i<(character_id); i++)
	{
		relationship_array[i].emplace_back(relationship_array[character_id][i]);
	}

	//show values
	/*if(character_id==9)
	{
		for(int ix=0; ix<num_participants; ix++)
		{
			std::cout << "character_id: " << ix << std::endl;
			for(int iy=0; iy<num_participants; iy++)
			{
				std::cout << relationship_array[ix][iy] << " ";
			}
			std::cout << std::endl;
		}
	}*/
	
	return character_id;
}

int sbr::relationships::get_status(int current_character_id, int other_character_id)
{
	return 	relationship_array[current_character_id][other_character_id];
}

void sbr::relationships::set_status(
	int current_character_id, 
	int other_character_id, 
	int new_status_value)
{
	//the new value has to be written into both characters relationships
	relationship_array[current_character_id][other_character_id]=new_status_value;
	relationship_array[other_character_id][current_character_id]=new_status_value;
}

void sbr::relationships::change_status(
	int current_character_id, 
	int other_character_id, 
	int delta_value)
{
	int value=get_status(current_character_id, other_character_id);
	value+=delta_value;
	set_status(current_character_id, other_character_id, value);
}
