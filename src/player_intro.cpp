#include <game.hpp>

#define INTRO_TEXT_LEFT (PLAYER_INTRO_X + 0.05)
#define INTRO_TEXT_UP (PLAYER_INTRO_Y + PLAYER_INTRO_SIZE_Y - CONVO_TEXT_SIZE_Y*2)


void sbr::player::intro()
{
	TG_object *win_obj=TG_new_object(
		PLAYER_INTRO_SIZE_X, PLAYER_INTRO_SIZE_Y, PLAYER_INTRO_X, PLAYER_INTRO_Y);
	TG_texture *win_tex=TG_new_texture("assets/window.png", 1, false);
	TG_object_use_texture(win_obj, win_tex);
	TG_font *text_regular=TG_new_font("assets/Itim-Regular.otf", 30);

	std::string press_enter("PRESS <ENTER> TO CONTINUE");
	TG_text *press_enter_text=TG_new_text(
		text_regular,
		press_enter.c_str(),
		press_enter.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-9*CONVO_TEXT_SIZE_Y, //lowest line
		TEXT_COLOR);

	//creating texts
	//page 0
	std::string welcome_s(GAME_NAME);
	TG_text *welcome=TG_new_text(
		text_regular,
		welcome_s.c_str(),
		welcome_s.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP, //first line
		TEXT_COLOR);

	std::string welcome_s2("Dracula celebrates his birthday once again.");
	TG_text *welcome2=TG_new_text(
		text_regular,
		welcome_s2.c_str(),
		welcome_s2.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-2*CONVO_TEXT_SIZE_Y, //third line
		TEXT_COLOR);

	std::string welcome_s3("He invited everyone in the nearby villages.");
	TG_text *welcome3=TG_new_text(
		text_regular,
		welcome_s3.c_str(),
		welcome_s3.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-3*CONVO_TEXT_SIZE_Y, //fourth line
		TEXT_COLOR);

	std::string welcome_s4("People are saying it's going to be the party");
	TG_text *welcome4=TG_new_text(
		text_regular,
		welcome_s4.c_str(),
		welcome_s4.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-4*CONVO_TEXT_SIZE_Y, //fifth line
		TEXT_COLOR);

	std::string welcome_s5("of the century.");
	TG_text *welcome5=TG_new_text(
		text_regular,
		welcome_s5.c_str(),
		welcome_s5.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-5*CONVO_TEXT_SIZE_Y, //sixth line
		TEXT_COLOR);

	std::string welcome_s6("No wonder, his last party was exactly that");
	TG_text *welcome6=TG_new_text(
		text_regular,
		welcome_s6.c_str(),
		welcome_s6.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-6*CONVO_TEXT_SIZE_Y, //seventh line
		TEXT_COLOR);
	
	std::string welcome_s7("long ago. The people are crazy about it.");
	TG_text *welcome7=TG_new_text(
		text_regular,
		welcome_s7.c_str(),
		welcome_s7.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-7*CONVO_TEXT_SIZE_Y, //eigth line
		TEXT_COLOR);

	//page1
	std::string page1_s("It's not just other people who want to go.");
	TG_text *page1_=TG_new_text(
		text_regular,
		page1_s.c_str(),
		page1_s.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-0*CONVO_TEXT_SIZE_Y, //first line
		TEXT_COLOR);

	std::string page1_s2("It's you as well. But the area around");
	TG_text *page1_2=TG_new_text(
		text_regular,
		page1_s2.c_str(),
		page1_s2.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-1*CONVO_TEXT_SIZE_Y, //second line
		TEXT_COLOR);

	std::string page1_s3("Dracula's castle is not particular busy.");
	TG_text *page1_3=TG_new_text(
		text_regular,
		page1_s3.c_str(),
		page1_s3.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-2*CONVO_TEXT_SIZE_Y, //third line
		TEXT_COLOR);

	std::string page1_s4("So it has been a while since the last party.");
	TG_text *page1_4=TG_new_text(
		text_regular,
		page1_s4.c_str(),
		page1_s4.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-3*CONVO_TEXT_SIZE_Y, //fourth line
		TEXT_COLOR);

	//weird shit
	//the engine apparently has a bug while creating texts
	//so I need this dummy
	TG_text *dummy=TG_new_text(
		text_regular,
		page1_s4.c_str(),
		page1_s4.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-3*CONVO_TEXT_SIZE_Y, //sixth line
		TEXT_COLOR);

	std::string page1_s5("You wonder how to behave there.");
	TG_text *page1_5=TG_new_text(
		text_regular,
		page1_s5.c_str(),
		page1_s5.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-4*CONVO_TEXT_SIZE_Y, //sixth line
		TEXT_COLOR);


	//page2
	std::string page2_s("According to Dracula you don't need anything");
	TG_text *page2_=TG_new_text(
		text_regular,
		page2_s.c_str(),
		page2_s.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-0*CONVO_TEXT_SIZE_Y, //first line
		TEXT_COLOR);

	std::string page2_s2("special. Just walk around with <WASD> and talk");
	TG_text *page2_2=TG_new_text(
		text_regular,
		page2_s2.c_str(),
		page2_s2.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-1*CONVO_TEXT_SIZE_Y, //first line
		TEXT_COLOR);

	std::string page2_s3("with people when you bump into them.");
	TG_text *page2_3=TG_new_text(
		text_regular,
		page2_s3.c_str(),
		page2_s3.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-2*CONVO_TEXT_SIZE_Y, //first line
		TEXT_COLOR);

	std::string page2_s4("You can make Dracula sad by leaving with <ESC>.");
	TG_text *page2_4=TG_new_text(
		text_regular,
		page2_s4.c_str(),
		page2_s4.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-3*CONVO_TEXT_SIZE_Y, //first line
		TEXT_COLOR);

	std::string page2_s5("Do you want to attend the party as a?");
	TG_text *page2_5=TG_new_text(
		text_regular,
		page2_s5.c_str(),
		page2_s5.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-5*CONVO_TEXT_SIZE_Y, //first line
		TEXT_COLOR);


	//weird shit
	//the engine apparently has a bug while creating texts
	//so I need this dummy
	TG_text *dummy2=TG_new_text(
		text_regular,
		page1_s4.c_str(),
		page1_s4.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-3*CONVO_TEXT_SIZE_Y, //sixth line
		TEXT_COLOR);

	std::string page2_s6("boy <B>   girl <G>");
	TG_text *page2_6=TG_new_text(
		text_regular,
		page2_s6.c_str(),
		page2_s6.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-6*CONVO_TEXT_SIZE_Y, //first line
		TEXT_COLOR);


	std::string boy_tmp("current choice: boy");
	TG_text *boy_text=TG_new_text(
		text_regular,
		boy_tmp.c_str(),
		boy_tmp.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-8*CONVO_TEXT_SIZE_Y, //first line
		TEXT_COLOR);

	std::string girl_tmp("current choice: girl");
	TG_text *girl_text=TG_new_text(
		text_regular,
		girl_tmp.c_str(),
		girl_tmp.length()*CONVO_LETTER_SIZE,
		CONVO_TEXT_SIZE_Y, 
		INTRO_TEXT_LEFT,
		INTRO_TEXT_UP-8*CONVO_TEXT_SIZE_Y, //first line
		TEXT_COLOR);

	int page=0;
	while(!TG_is_key_pressed(SDL_SCANCODE_ESCAPE))
	{
		TG_render_object(win_obj);
		if(page==2)
		{
			TG_render_text(page2_);
			TG_render_text(page2_2);
			TG_render_text(page2_3);
			TG_render_text(page2_4);
			TG_render_text(page2_5);
			TG_render_text(page2_6);
			if(sex==NPC_MALE)
			{
				TG_render_text(boy_text);
			}
			if(sex==NPC_FEMALE)
			{
				TG_render_text(girl_text);
			}
			TG_render_text(press_enter_text);

			if(TG_is_key_pressed(SDL_SCANCODE_B))
			{
				sex=NPC_MALE;
			}
			if(TG_is_key_pressed(SDL_SCANCODE_G))
			{
				sex=NPC_FEMALE;
			}
		}
		else if(page==1)
		{
			TG_render_text(page1_);
			TG_render_text(page1_2);
			TG_render_text(page1_3);
			TG_render_text(page1_4);
			TG_render_text(page1_5);
			TG_render_text(press_enter_text);
		}
		else if(page==0)
		{
			TG_render_text(welcome);
			TG_render_text(welcome2);
			TG_render_text(welcome3);
			TG_render_text(welcome4);
			TG_render_text(welcome5);
			TG_render_text(welcome6);
			TG_render_text(welcome7);
			TG_render_text(press_enter_text);
		}
		else
		{
			break; //continue with the game
		}

		static bool key_down=false;
		if(TG_is_key_pressed(SDL_SCANCODE_RETURN) && !key_down)
		{
			//cleanup
			if(page==0)
			{
				TG_destroy_text(welcome);
				TG_destroy_text(welcome2);
				TG_destroy_text(welcome3);
				TG_destroy_text(welcome4);
				TG_destroy_text(welcome5);
				TG_destroy_text(welcome6);
				TG_destroy_text(welcome7);
			}
			key_down=true;
			page++;

		}
		if(!TG_is_key_pressed(SDL_SCANCODE_RETURN))
		{
			key_down=false;
		}

		TG_new_frame(SEA_COLOR);
	}

	TG_destroy_object(win_obj);
	TG_destroy_texture(win_tex);
	TG_destroy_font(text_regular);
}