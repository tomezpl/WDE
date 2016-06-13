// htmlsource.h
// Header file for the HTMLSource class.

#ifndef WDE_HTMLSOURCE
#define WDE_HTMLSOURCE

#define WDE_HTML_DIR "/var/cache/wbdehtml/"
#define WDE_LOCAL_HOSTNAME "http://127.0.0.1:1337/"

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
			std::string m_HTMLstr; // HTML string to be used by WebKit if reading from file
			std::string m_URIstr; // URI string to be used by WebKit
		public:
			// Default constructor
			HTMLSource();
			
			// Constructor that will call LoadFromFile
			HTMLSource(std::string pathStr);
			
			// Destructor
			~HTMLSource();
			
			// Fill m_HTMLstr with contents of the file in pathStr
			// Note that this does not work with AJAX
			void LoadFromFile(std::string pathStr);
			
			// WDE normally has a local HTTP server running
			// Use this method to load a page from that server
			void LoadFromLocalhost(std::string resStr);
			
			// Load a page from any URI
			void LoadFromURI(std::string uriStr);
			
			// WebKitGTK loads strings in gchar datatype
			// This function will convert the HTML string to an array of characters
			gchar* GetHTML();
			
			// WebKitGTK loads URIs in gchar datatype
			// This function will convert the URI string to an array of characters
			gchar* GetURI();
	};
}

#endif
