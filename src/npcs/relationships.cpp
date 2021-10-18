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
		int value=RELATIONSHIP_START;
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
	for(int i=0; i<(num_participants-1); i++)
	{
		relationship_array[i].emplace_back(value);
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
	}
	*/
	return character_id;
}

