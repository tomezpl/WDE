#ifndef WDE_HTTPSERVER
#define WDE_HTTPSERVER

#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <microhttpd.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#define HTTP_PORT 1337

namespace WDE {
	class HTTPServer {
		private:
			struct MHD_Daemon* m_HTTPD;
			struct MHD_Response* m_Response;
			
			// Status of the HTTP daemon
			// This can be either:
			// -1 (failed to create)
			// 0 (not created)
			// 1 (successfully created)
			short m_Status;
			
			/*int HandleRequest  
				(void* cls, struct MHD_Connection* connection,
				 const char* url, const char* method,
				 const char* version, const char* data,
				 size_t* data_size, void** con_cls);*/
		public:
			static int CallHandler
				(void* cls, struct MHD_Connection* connection,
				 const char* url, const char* method,
				 const char* version, const char* data,
				 size_t* data_size, void** con_cls);
			 HTTPServer();
			 ~HTTPServer();
	};
}

#endif