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
	public:
		conversation();
		~conversation();
		void make_active(){active_convo=true;};
		void render();
	};
}

#endif