// utilfunc.h
// Header file for the Utility class, which contains various utility functions.

#ifndef WDE_UTILITY_FUNCTIONS
#define WDE_UTILITY_FUNCTIONS

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

namespace WDE
{
	class Utility {
		private:
			static bool m_IsOutputBusy;
		public:
			static std::string GetOutput(std::string command);
	};
}

#endif