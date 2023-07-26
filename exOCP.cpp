#include <iostream>
#include <vector> 

// ref : https://www.vishalchovatiya.com/open-closed-principle-in-cpp-solid-as-a-rock/

using namespace std; 

enum class COLOR { RED, GREEN, BLUE }; 
enum class SIZE { SMALL, MEDIAUM, LARGE }; 

struct Product {
    string m_name; 
    COLOR  m_color; 
    SIZE m_size; 
};

using Items = vector<Product*>; 
#define ALL(C) begin(C), end(C) 

struct ProductFilter {
    static Items by_coor(Items items, const COLOR e_color) {
        Items result; 
    }
}

int main(void) 
{

    return 0; 
}
