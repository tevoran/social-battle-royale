#include "game.hpp"
#include "conversation.hpp"

sbr::conversation::conversation()
{
	//window sprite
	win_obj=TG_new_object(CONVO_SIZE_X, CONVO_SIZE_Y, 0.0, 0.0);
	win_tex=TG_new_texture("assets/window.png", 1, false);
	TG_object_use_texture(win_obj, win_tex);

	text_regular=TG_new_font("assets/Itim-Regular.otf", 30);
}

sbr::conversation::~conversation()
{
	TG_destroy_object(win_obj);
	TG_destroy_texture(win_tex);
}

void sbr::conversation::active(bool is_active)
{
	active_convo=is_active;
	if(active_convo==false)
	{
		active_texts.clear();
	}
}

void sbr::conversation::add_line(std::string string)
{
	float pos_y=
		(CONVO_SIZE_Y - CONVO_TEXT_SIZE_Y/10.0)
		 - (CONVO_TEXT_SIZE_Y * (active_texts.size()+1));
	TG_text *text_tmp=TG_new_text(
		text_regular, 
		string.c_str(), 
		string.length()*CONVO_LETTER_SIZE, 
		CONVO_TEXT_SIZE_Y, 
		CONVO_TEXT_LEFT, 
		pos_y, 
		TEXT_COLOR);
	active_texts.emplace_back(text_tmp);
}

void sbr::conversation::clear()
{
	for(int i=0; i<active_texts.size(); i++)
	{
		TG_destroy_text(active_texts[i]);
	}
	active_texts.clear();
}

void sbr::conversation::render()
{
	if(active_convo)
	{
		TG_render_object(win_obj);

		for(int i=0; i<active_texts.size(); i++)
		{
			TG_render_text(active_texts[i]);
		}
	}
}