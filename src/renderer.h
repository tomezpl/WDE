#ifndef WDE_RENDERER
#define WDE_RENDERER

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>
#include <Awesomium/WebCore.h>

namespace WDE
{
	class Renderer
    {
        private:
            sf::RenderWindow* m_Window;
        
            Awesomium::WebCore* m_WebCore;
            Awesomium::WebSession* m_WebSession;
            Awesomium::WebView* m_WebView;
            Awesomium::BitmapSurface* m_BitmapSurface;
            
            unsigned short m_Width;
            unsigned short m_Height;
        
        public:
            Renderer(unsigned short width, unsigned short height);
            void RenderHTML();
            void MainLoop();
            ~Renderer();
    };
}

#endif