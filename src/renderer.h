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
            GtkWindow* m_Window;
        
            WebKitWebView* m_WebView;
			
			WDE::HTMLSource* m_HTMLSource;
        public:
			// Initialise GTK+ before using it.
			gboolean InitGTK(int &argc, char* argv[]);
			
			gboolean DestroyWebView(WebKitWebView* webView, GtkWidget* window);
			
            Renderer(unsigned short width, unsigned short height, int &argc, char* argv[]);
            void MainLoop();
            ~Renderer();
    };
}

#endif
