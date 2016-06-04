// main.cc
// This will start a WDE session.

#include "renderer.h"

int main(int argc, char* argv[])
{
	WDE::Renderer* renderer = new WDE::Renderer(1280, 720, argc, argv);
	renderer->MainLoop();
	delete renderer;
	
	return 0;
}
