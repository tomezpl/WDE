#include "Renderer.h"

using namespace WDE;
using namespace sf;
using namespace Awesomium;

Renderer::Renderer(unsigned short width, unsigned short height)
{
    m_Window = new RenderWindow(VideoMode(width, height), "WDE Desktop");
    m_WebCore = WebCore::Initialize(WebConfig());
    m_WebSession = m_WebCore->CreateWebSession(WSLit(""), WebPreferences());
    m_WebView = m_WebCore->CreateWebView(width, height);
    
    WebURL url(WSLit("http://www.google.com"));
    m_WebView->LoadURL(url);
}

void Renderer::RenderHTML()
{
    while(m_WebView->IsLoading())
	{
		m_WebCore->Update();
	}
	m_WebCore->Update();
	
	m_BitmapSurface = (BitmapSurface*)m_WebView->surface();
	
	if(m_BitmapSurface != 0)
	{
		m_BitmapSurface->SaveToJPEG(WSLit("./output.jpg"));
	}
}

void Renderer::MainLoop()
{
    Event event;
    while(m_Window->isOpen())
    {
        while(m_Window->pollEvent(event))
        {
            if(event.type == Event::Closed)
                m_Window->close();
        }
        
        m_Window->clear(Color(100, 149, 237));
        m_Window->display();
    }
}

Renderer::~Renderer()
{
    m_WebView->Destroy();
	m_WebSession->Release();
	WebCore::Shutdown();
}