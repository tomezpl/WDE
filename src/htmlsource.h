#ifndef WDE_HTMLSOURCE
#define WDE_HTMLSOURCE

#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <gtk/gtk.h>

namespace WDE
{
	class HTMLSource {
		private:
			std::string m_HTMLstr;
		public:
			HTMLSource();
			HTMLSource(std::string pathStr);
			~HTMLSource();
			
			void LoadFromFile(std::string pathStr);
			gchar* GetHTML();
	};
}

#endif