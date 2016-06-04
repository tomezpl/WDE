// main.cc
// This will start a WDE session.

#include "renderer.h"

int main(int argc, char* argv[])
{
	WDE::Renderer::InitGTK(argc, argv); // Initialise GTK before doing anything
	WDE::Renderer* renderer = new WDE::Renderer(1280, 720); // Create a new renderer
	
	// Start the main renderer loop.
	// This should run in its own thread, but right now it doesn't.
	renderer->MainLoop();
	
	// Deallocate memory used by the renderer when you're done
	delete renderer;
	
	// Exit with status 0 (no error)
	return 0;
}
