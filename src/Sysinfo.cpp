#include <iostream>
#include <stdlib.h> // the getenv call
#include <sys/sysinfo.h> // the system uptime call
using namespace std;


int main()
{
	struct sysinfo info; // system stats
	sysinfo(&info);      // retrieve the data

	char *value = getenv("REMOTE_ADDR"); // The remote address CGI environment variable

	cout << "Content-type:text/html\r\n";
	cout << "<html><head>\n";
	cout << "<title>EBB C++ Uptime</title>\n";
	cout << "</head><body>\n";
	cout << "<h1>BeagleBone System Uptime</h1>\n";

	int mins = info.uptime / 60;                   // the uptime comes from the sysinfo struct
	int ram = info.freeram / 1024 / 1024;          // the available memory in Mb

	cout << "<div> The system uptime is " << mins << " minutes.\n";
	cout << "There is " << ram << " Mb of memory available.</div>\n";
	cout << "<div> The CGI REMOTE_ADDR environment variable is " << value << "</div>";
	cout << "</body></html>\n";

	return 0;
}
