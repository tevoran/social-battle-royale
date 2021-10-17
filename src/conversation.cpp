#include "game.hpp"
#include "conversation.hpp"

sbr::conversation::conversation()
{
	//window sprite
	win_obj=TG_new_object(CONVO_SIZE_X, CONVO_SIZE_Y, 0.0, 0.0, 1);
	win_tex=TG_new_texture("assets/window.png", false);
	TG_use_texture_object(win_obj, win_tex);
}

sbr::conversation::~conversation()
{
	TG_destroy_object(win_obj);
	TG_destroy_texture(win_tex);
}

void sbr::conversation::render()
{
	std::cout << "active_convo: " << active_convo << std::endl;
	if(active_convo)
	{
		TG_render_object(win_obj);
	}
}