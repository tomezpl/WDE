#include "httpserver.h"
#include "htmlsource.h"

using namespace WDE;
using namespace std;

int HandleRequest 
			(void* cls, struct MHD_Connection* connection,
			 const char* url, const char* method,
			 const char* version, const char* data,
			 size_t* data_size, void** con_cls)
{
	/*if(m_Status == -1)
		return -1;*/
	const char* responseStr = "";
	string urlStr = url;
	cout << "HTTPD:\n\tRequested URL: " << urlStr << endl;
	
	if(urlStr == "/shutdown")
	{
		cout << "HTTPD:\n\tRequested SHUTDOWN command. Terminating process." << endl;
		exit(EXIT_SUCCESS);
	}
	else if(urlStr == "/desktop.html")
	{
		HTMLSource* html = new HTMLSource();
		string pathStr = WDE_HTML_DIR;
		pathStr.append(url);
		html->LoadFromFile(pathStr);
		responseStr = html->GetHTML();
	}
	
	int ret;
	struct MHD_Response* response;
	response = MHD_create_response_from_buffer(
										strlen(responseStr),
										(void*)responseStr,
										MHD_RESPMEM_PERSISTENT);
	ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
	MHD_destroy_response(response);
	return ret;
}

HTTPServer::HTTPServer()
{
	m_HTTPD = MHD_start_daemon(
								MHD_USE_SELECT_INTERNALLY, 
								HTTP_PORT, NULL, NULL,
								&HandleRequest, NULL,
								MHD_OPTION_END);
	if(daemon == NULL)
		m_Status = -1;
	else
		m_Status = 1;
}

HTTPServer::~HTTPServer()
{
	MHD_stop_daemon(m_HTTPD);
}