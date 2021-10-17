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
}

#endif