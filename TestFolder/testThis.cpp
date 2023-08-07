#include <iostream>

using namespace std; 

struct PStruct {
    PStruct() : m_width{10}, m_height{20} {} 

    int m_width, m_height; 
};

struct CStruct : PStruct {
    CStruct() : PStruct() {} 

    void print() { 
        // this->m_width = 30; 
        // this->m_height = 40;

        m_width = 30; 
        m_height = 40;      
        cout << this->m_width << this->m_height << m_width << m_height << endl; 
    }
};

int main() 
{
    CStruct ob = CStruct(); 
    ob.print(); 

    return EXIT_SUCCESS; 
}