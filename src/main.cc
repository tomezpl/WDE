// main.cc
// This will start a WDE session.

#include "renderer.h"

int main()
{
	WDE::Renderer* renderer = new WDE::Renderer(1280, 720);
	renderer->RenderHTML();
	renderer->MainLoop();
	delete renderer;
	
	return 0;
}
