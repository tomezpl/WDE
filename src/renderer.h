// renderer.h
// Header file for the Renderer class.

#ifndef WDE_RENDERER
#define WDE_RENDERER

#include <gtk/gtk.h>
#include <webkit/webkit.h>
#include <iostream>

#include "htmlsource.h"

namespace WDE
{
	class Renderer
    {
        private:
			// Root window of the program
            GtkWindow* m_Window;

			// Main webview
			WebKitWebView* m_WebView;
			
			// Main HTML source
			WDE::HTMLSource* m_HTMLSource;
        public:
			// Initialise GTK+ before using it.
			static gboolean InitGTK(int &argc, char* argv[]);
			
			// Callback function for WebKitGTK to call when the web view needs to be destroyed
			static gboolean DestroyWebView(WebKitWebView* webView, GtkWidget* window);
			
			// Constructor that will create a window and a webview based on the resolution
            Renderer(unsigned short width, unsigned short height);
            
            // Main renderer loop - this should run in its own thread
            void MainLoop();
            
            // Destructor
            ~Renderer();
    };
}

#endif
