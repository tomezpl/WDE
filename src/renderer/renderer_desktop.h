// renderer/renderer_desktop.cc
// Header file for the DesktopRenderer class

#ifndef WDE_RENDERER_DESKTOP
#define WDE_RENDERER_DESKTOP

#include "renderer_base.h"

namespace WDE 
{
	class DesktopRenderer : public BaseRenderer
	{
		public:
			DesktopRenderer(unsigned short width, unsigned short height, char* argv[]);
	};
}

#endif