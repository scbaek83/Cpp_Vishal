#include <iostream> 
#include <string> 
#include <sstream>

using namespace std; 

int main() 
{
    auto text = "hello"; 
    string output; 
    output += "<p>"; 
    output += text; 
    output += "</p>"; 

    string words[] = {"hello", "world"}; 
    ostringstream oss; 
    oss << "<ul>"; 
    for (auto w : words) 
        oss << " <li>" << w << "</li>"; 
    oss << "</ul>"; 

    printf(oss.str().c_str());

    return EXIT_SUCCESS;
}