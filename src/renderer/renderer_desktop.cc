// renderer/renderer_desktop.cc
// This implements the DesktopRenderer class

#include "renderer_desktop.h"

using namespace WDE;

DesktopRenderer::DesktopRenderer(unsigned short width, unsigned short height, char* argv[]): BaseRenderer(width, height, argv)
{
	gtk_window_set_type_hint(m_Window, GDK_WINDOW_TYPE_HINT_DESKTOP);
}