#include "renderer.h"

using namespace WDE;
using namespace std;

gboolean Renderer::DestroyWebView(WebKitWebView* webView, GtkWidget* window)
{
	gtk_widget_destroy(window);
	return TRUE;
}

static gboolean DestroyWebKit(WebKitWebView* webView, GtkWidget* window)
{
	gtk_widget_destroy(window);
	return TRUE;
}

Renderer::Renderer(unsigned short width, unsigned short height, int &argc, char* argv[])
{
	InitGTK(argc, argv);
	m_Window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
	gtk_window_resize(m_Window, width, height);
	g_signal_connect(GTK_WIDGET(m_Window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	m_WebView = WEBKIT_WEB_VIEW(webkit_web_view_new());
	g_signal_connect(GTK_WIDGET(m_WebView), "close", G_CALLBACK(DestroyWebKit), m_Window);
	gtk_container_add(GTK_CONTAINER(m_Window), GTK_WIDGET(m_WebView));
	
	m_HTMLSource = new HTMLSource("./html/index.html");
	webkit_web_view_load_string(m_WebView, m_HTMLSource->GetHTML(), NULL, NULL, NULL);
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
