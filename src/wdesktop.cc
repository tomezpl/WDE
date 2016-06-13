// main.cc
// This will start a WDE session.

#include "renderer.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
	WDE::Renderer::InitGTK(argc, argv); // Initialise GTK before doing anything
	WDE::Renderer* renderer = new WDE::Renderer(640, 480, argv); // Create a new renderer
	
	// Since this will be the root window, it must be fullscreen
	renderer->GoFullscreen();
	
	// Start the main renderer loop.
	// This should run in its own thread, but right now it doesn't.
	renderer->MainLoop();
	
	// Deallocate memory used by the renderer when you're done
	delete renderer;
	
	// Exit with status 0 (no error)
	return 0;
}
