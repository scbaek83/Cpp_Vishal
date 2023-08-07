#include <iostream> 

using namespace std; 

struct Office { 
    string m_street; 
    string m_city; 
    int32_t m_cubical; 

    Office(string s, string c, int32_t n) : m_street(s), m_city(c), m_cubical(n) {} 
}; 

struct Employee {
    string m_name; 
    Office m_office; 

    Employee(string n, Office o) : m_name(n), m_office(o) {} 
};

int main() 
{
    Employee john{ "John Doe", Office{"123 East Dr", "London", 123} }; 
    Employee jane{ "Jane Doe", Office{"123 East Dr", "London", 124} }; 
    Employee jack{ "Jack Doe", Office{"123 ORR", "Bangaluru", 300} };

    return EXIT_SUCCESS; 
}