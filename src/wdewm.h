// wdewm.h
// Header file for WindowManager class that allows to manipulate X windows.

#ifndef WDE_WINDOW_MANAGER
#define WDE_WINDOW_MANAGER

#include <stdlib.h>
#include <string>
#include "utilfunc.h"

namespace WDE
{
	class WindowManager
	{
		private:
			static const char* m_GetWindowListCommand;
		public:
			static std::string GetAllWindows();
	};
}

#endif