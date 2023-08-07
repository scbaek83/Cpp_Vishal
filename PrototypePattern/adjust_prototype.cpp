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
    const Office* m_office; 

    Employee(string n, Office *o) : m_name(n), m_office(o) {} 
};

static Office LondonOffice{"123 East DR", "London", 123}; 
static Office BangaluruOffice{"RMZ Ecoworld ORR", "London", 123}; 

int main() 
{
    Employee john{"John Doe", &LondonOffice}; 
    Employee jane{"Jane Doe", &LondonOffice}; 
    Employee jack{"Jack Doe", &BangaluruOffice};

    return EXIT_SUCCESS;
}