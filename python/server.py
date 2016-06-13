from SimpleHTTPServer import SimpleHTTPRequestHandler
import BaseHTTPServer
import os

PORTNUMBER = 1337

class CORSRequestHandler (SimpleHTTPRequestHandler):
    def end_headers(self):
        self.send_header('Access-Control-Allow-Origin', '*')
        SimpleHTTPRequestHandler.end_headers(self)

if __name__ == '__main__':
    server_class = BaseHTTPServer.HTTPServer
    os.chdir("/var/cache/wbdehtml/")
    httpd = server_class(("", PORTNUMBER), CORSRequestHandler)
    print "Listening at localhost. Port",PORTNUMBER
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        pass
    httpd.server_close()