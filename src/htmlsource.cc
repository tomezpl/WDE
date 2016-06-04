#include "htmlsource.h"

using namespace WDE;
using namespace std;

void HTMLSource::LoadFromFile(string pathStr)
{
	stringstream ss;
	ifstream ifs;
	ifs.open(pathStr.c_str(), ifstream::in);
	string currentLine;
	if(ifs.good())
	{
		while(getline(ifs, currentLine))
		{
			ss << currentLine << "\n";
		}
	}
	ifs.close();
	m_HTMLstr = ss.str();
}

HTMLSource::HTMLSource(string pathStr)
{
	LoadFromFile(pathStr);
}