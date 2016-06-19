// renderer/renderer_base.h
// Header file for the BaseRenderer class.

#ifndef WDE_RENDERER_BASE
#define WDE_RENDERER_BASE

#define WDE_RENDERER_DEF_WIDTH 1920
#define WDE_RENDERER_DEF_HEIGHT 1080

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include <iostream>
#include <string>

#include "../htmlsource.h"

namespace WDE
{
	class BaseRenderer
    {
        private:
			// Root window of the program and its size
            GtkWindow* m_Window;
			gint m_WindowWidth;
			gint m_WindowHeight;

			// Main webview
			WebKitWebView* m_WebView;
			
			// Main settings
			WebKitSettings* m_WebSettings;
			
			// Main context
			WebKitWebContext* m_WebContext;
			
			// Main security manager
			WebKitSecurityManager* m_WebSecurityManager;
			
			// Main HTML source
			WDE::HTMLSource* m_HTMLSource;
			
			bool m_IsFullscreen;
			
			void UpdateSize();
        public:
			// Initialise GTK+ before using it.
			static gboolean InitGTK(int &argc, char* argv[]);
			
			// Callback function for WebKitGTK to call when the web view needs to be destroyed
			static gboolean DestroyWebView(WebKitWebView* webView, GtkWidget* window);
			
			// Constructor that will create a window and a webview based on the resolution
			// It will also load the HTML file specified as the first argument
			// (hence argument array needs to be passed to argv)
            BaseRenderer(unsigned short width, unsigned short height, char* argv[]);
            
			// Switch window types
			void GoFullscreen();
			void GoWindowed();
			void ToggleFullscreen();
			
            // Main renderer loop - this should run in its own thread
            void MainLoop();
            
            // Destructor
            ~BaseRenderer();
    };
}

#endif
