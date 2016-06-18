// htmlsource.cc
// This implements the HTMLSource class.
// It is used to load and store HTML contents from a file.

#include "htmlsource.h"

using namespace WDE;
using namespace std;

void HTMLSource::LoadFromFile(string pathStr)
{
	stringstream ss; // stringstream that we will write the HTML contents to
	ifstream ifs; // input filestream that we will read the HTML from
	
	ifs.open(pathStr.c_str(), ifstream::in);
	string currentLine; // since we read line-by-line, this will act as a buffer
	
	// this checks that the file is readable
	if(ifs.good())
	{
		while(getline(ifs, currentLine)) // read the current line from the stream
		{
			ss << currentLine << "\n"; // append a newline character after the current line
		}
	}
	ifs.close(); // close the stream when you're done
	m_HTMLstr = ss.str(); // retrieve the string from the stringstream
}

void HTMLSource::LoadFromURI(string uriStr)
{
	m_HTMLstr = "";
	m_URIstr = uriStr;
}

void HTMLSource::LoadFromLocalhost(string resStr)
{
	m_HTMLstr = "";
	m_URIstr = WDE_LOCAL_HOSTNAME;
	m_URIstr.append(resStr);
}

const char* HTMLSource::GetHTML()
{
	return m_HTMLstr.c_str(); // return an array of characters
}

const char* HTMLSource::GetURI()
{
	return m_URIstr.c_str();
}

HTMLSource::HTMLSource(string resStr)
{
	LoadFromLocalhost(resStr);
}

HTMLSource::HTMLSource()
{
	
}

HTMLSource::~HTMLSource()
{
	// this should be updated... at some point
}
