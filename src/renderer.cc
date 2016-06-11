// renderer.cc
// This implements the Renderer class.
// It is used to render and display the UI in a GTK window.

#include "renderer.h"

using namespace WDE;
using namespace std;

gboolean Renderer::DestroyWebView(WebKitWebView* webView, GtkWidget* window)
{
	gtk_widget_destroy(window);
	return TRUE;
}

Renderer::Renderer(unsigned short width, unsigned short height, char* argv[])
{
	m_IsFullscreen = false;
	
	m_Window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
	gtk_window_resize(m_Window, width, height);
	g_signal_connect(GTK_WIDGET(m_Window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	m_WebView = WEBKIT_WEB_VIEW(webkit_web_view_new());
	g_signal_connect(GTK_WIDGET(m_WebView), "close", G_CALLBACK(DestroyWebView), m_Window);
	gtk_container_add(GTK_CONTAINER(m_Window), GTK_WIDGET(m_WebView));
	
	m_HTMLSource = new HTMLSource(argv[1]);
	webkit_web_view_load_string(m_WebView, m_HTMLSource->GetHTML(), NULL, NULL, NULL);
}

void Renderer::GoFullscreen()
{
	m_IsFullscreen = true;
	gtk_window_fullscreen(m_Window);
	GdkScreen* defScreen = gdk_screen_get_default();
	gtk_window_resize(m_Window, gdk_screen_get_width(defScreen), gdk_screen_get_height(defScreen));
}

void Renderer::GoWindowed()
{
	m_IsFullscreen = false;
	gtk_window_unfullscreen(m_Window);
}

void Renderer::ToggleFullscreen()
{
	if(m_IsFullscreen)
		GoWindowed();
	else
		GoFullscreen();
}

void Renderer::MainLoop()
{
	gtk_window_present(m_Window);
	gtk_widget_show_all(GTK_WIDGET(m_Window));
    gtk_main();
}

// Initialise GTK+ before using it.
gboolean Renderer::InitGTK(int &argc, char* argv[])
{
	gboolean success = gtk_init_check(&argc, &argv);
	if(success)
		cout << "GTK+ initialised successfully." << endl;
	else
		cout << "There was a problem initialising GTK+." << endl;
	return success;
}

Renderer::~Renderer()
{
	delete m_WebView;
	delete m_Window;
	delete m_HTMLSource;
}
