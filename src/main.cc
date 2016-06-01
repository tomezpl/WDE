#include "Renderer.h"

int main()
{
	/*WebCore* web_core = WebCore::Initialize(WebConfig());
	WebSession* web_session = web_core->CreateWebSession(WSLit(""), WebPreferences());
	WebView* web_view = web_core->CreateWebView(800, 600);
	
	WebURL url(WSLit("http://www.google.com"));
	web_view->LoadURL(url);
	
	while(web_view->IsLoading())
	{
		UpdateApplication(web_core);
	}
	UpdateApplication(web_core);
	
	BitmapSurface* surface = (BitmapSurface*)web_view->surface();
	
	if(surface != 0)
	{
		surface->SaveToJPEG(WSLit("./result.jpg"));
	}
	
	web_view->Destroy();
	web_session->Release();
	WebCore::Shutdown();*/
	
	WDE::Renderer* renderer = new WDE::Renderer(1280, 720);
	renderer->RenderHTML();
	renderer->MainLoop();
	delete renderer;
	
	return 0;
}
