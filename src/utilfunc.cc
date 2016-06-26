// utilfunc.cc
// This implements the Utility class

#include "utilfunc.h"

using namespace WDE;
using namespace std;

bool Utility::m_IsOutputBusy = false;

string Utility::GetOutput(string command)
{
	if(m_IsOutputBusy)
		return "";
	m_IsOutputBusy = true;
	command.append(" > /tmp/.wdeoutput");
	system(command.c_str());
	ifstream ifs("/tmp/.wdeoutput", ifstream::in);
	stringstream ss;
	string ret = "";
	while(ifs.good())
	{
		string line = "";
		getline(ifs, line);
		line.append("\n");
		ret.append(line);
	}
	ifs.close();
	m_IsOutputBusy = false;
	return ret;
}