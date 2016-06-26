// wdewm.cc
// This implements the WindowManager class.

#include "wdewm.h"

using namespace WDE;
using namespace std;

const char* WindowManager::m_GetWindowListCommand = "xlsclients -l | grep \"Window 0x\" | sed 's/Window //g' | sed 's/://g' | xargs -L1 xwininfo -id | grep \"xwininfo: Window id: 0x\" | sed 's/xwininfo: Window id: //g'";

string WindowManager::GetAllWindows()
{
	return Utility::GetOutput(m_GetWindowListCommand);
}