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
		void active(bool is_active){active_convo=is_active;};
		void render();
	};
}

#endif