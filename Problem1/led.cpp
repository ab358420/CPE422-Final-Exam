// errors when outputting on or off readings

#include <iostream>         // for the input/output
#include <stdlib.h>         // for the getenv call
#include <sys/sysinfo.h>    // for the system uptime call
#include <cgicc/Cgicc.h>    // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#define LED_GPIO "/sys/class/gpio/gpio60/"
using namespace std;
using namespace cgicc;

int readGPIO(string value){
   fstream fs;
   string path(LED_GPIO),x;
   fs.open((path).c_str(), fstream::in);
   fs << value;
   fs >> x;
   int n = stoi(x); // convert string to integer
   return n;
   fs.close();
}

int main(){
   Cgicc form;                      // the CGI form object
//   readGPIO("direction", "in");
 
   // generate the form but use states that are set in the submitted form
   cout << HTTPHTMLHeader() << endl;       // Generate the HTML form
   cout << html() << head() << title("Ashley Bonilla") << head() << endl;
   cout << body().set("style","background-color:Gold") << h1("CPE 422 Final Exam: Reading Digital Input").set("style","color:Blue") << endl;
   cout << body() << h1("Reading a GPIO Pin via a Web Browser").set("style","color:Blue") << endl;
   cout << "<form action=\"/cgi-bin/led.cgi\" method=\"POST\">\n";
   cout << "<div>";
   cout << "<input type=\"submit\" value=\"Read Switch\" />";
   cout << body() << h1("Switch State: ") << endl;
 //  cout << "</div></form>";
 
   int n;
   n = readGPIO("value"); 
  cout << "<div>";
  if ( n == 1) 
 { cout << body() << h1("ON") << endl;}
  else  
  cout << body() << h1("OFF") << endl;
   
    cout << "</div></form>";
 cout << body() << html();
   return 0;
}
