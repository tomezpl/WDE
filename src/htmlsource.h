// htmlsource.h
// Header file for the HTMLSource class.

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
			std::string m_HTMLstr; // HTML string to be used by WebKit
		public:
			// Default constructor
			HTMLSource();
			
			// Constructor that will call LoadFromFile
			HTMLSource(std::string pathStr);
			
			// Destructor
			~HTMLSource();
			
			// Fill m_HTMLstr with contents of the file in pathStr
			void LoadFromFile(std::string pathStr);
			
			// WebKitGTK loads strings in gchar datatype
			// This function will convert the HTML string to an array of characters
			gchar* GetHTML();
	};
}

#endif
