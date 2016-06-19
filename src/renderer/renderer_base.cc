// renderer/renderer_base.cc
// This implements the BaseRenderer class.
// It is used to render and display the UI in a GTK window.

#include "renderer_base.h"

using namespace WDE;
using namespace std;

gboolean BaseRenderer::DestroyWebView(WebKitWebView* webView, GtkWidget* window)
{
	gtk_widget_destroy(window);
	return TRUE;
}

BaseRenderer::BaseRenderer(unsigned short width, unsigned short height, char* argv[])
{
	m_IsFullscreen = false;
	
	m_WebContext = webkit_web_context_get_default();
	m_WebSecurityManager = webkit_web_context_get_security_manager(m_WebContext);
	
	m_WebSettings = webkit_settings_new();
	
	m_WindowWidth = width;
	m_WindowHeight = height;
	
	m_Window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
	gtk_window_resize(m_Window, m_WindowWidth, m_WindowHeight);
	g_signal_connect(GTK_WIDGET(m_Window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	m_WebView = WEBKIT_WEB_VIEW(webkit_web_view_new());
	g_signal_connect(GTK_WIDGET(m_WebView), "close", G_CALLBACK(DestroyWebView), m_Window);
	webkit_web_view_set_settings(m_WebView, m_WebSettings);
	gtk_container_add(GTK_CONTAINER(m_Window), GTK_WIDGET(m_WebView));
	
	m_HTMLSource = new HTMLSource(argv[1]);
	webkit_web_view_load_uri(m_WebView, m_HTMLSource->GetURI());
}

void BaseRenderer::GoFullscreen()
{
	m_IsFullscreen = true;
	gtk_window_fullscreen(m_Window);
	GdkScreen* defScreen = gdk_screen_get_default();
	gtk_window_resize(m_Window, gdk_screen_get_width(defScreen), gdk_screen_get_height(defScreen));
	UpdateSize();
	gtk_widget_set_hexpand(GTK_WIDGET(m_Window), FALSE);
	gtk_widget_set_vexpand(GTK_WIDGET(m_Window), FALSE);
}

void BaseRenderer::GoWindowed()
{
	m_IsFullscreen = false;
	gtk_window_unfullscreen(m_Window);
	UpdateSize();
}

void BaseRenderer::ToggleFullscreen()
{
	if(m_IsFullscreen)
		GoWindowed();
	else
		GoFullscreen();
}

void BaseRenderer::UpdateSize()
{
	// Reset size
	m_WindowWidth = 0;
	m_WindowHeight = 0;
	
	// Update size
	gtk_window_get_size(m_Window, &m_WindowWidth, &m_WindowHeight);
}

void BaseRenderer::MainLoop()
{
	gtk_window_present(m_Window);
	gtk_widget_show_all(GTK_WIDGET(m_Window));
    gtk_main();
}

// Initialise GTK+ before using it.
gboolean BaseRenderer::InitGTK(int &argc, char* argv[])
{
	gboolean success = gtk_init_check(&argc, &argv);
	if(success)
		cout << "GTK+ initialised successfully." << endl;
	else
		cout << "There was a problem initialising GTK+." << endl;
	return success;
}

BaseRenderer::~BaseRenderer()
{
	delete m_WebView;
	delete m_Window;
	delete m_HTMLSource;
}
