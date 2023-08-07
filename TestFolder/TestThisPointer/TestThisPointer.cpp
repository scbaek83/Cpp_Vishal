#include <iostream>
using namespace std; 

class Builder; 

class Person {
    int value1; 
    int value2; 
    Person(int value) : value1(value) { printf("Person Constructor vlaue: %d\n", value1); } 
public: 
    friend class Builder; 
    static Builder create(int value);
};



class Builder {
    Person p1; 
public: 
    Builder(int value) : p1(value) { printf("Builder constructor: %d\n", value); } 
    // Builder(int value) : { 
    //     printf("Builder constructor: %d\n", value); 
    //     // p1(value);    
    //     p1.value1 = value; 
    //     return *this; 
    // } 

    operator Person() const { 
        printf("operator Person()\n"); 
        return move(p1); 
    } 

    Builder& updateValue2(int v) {
        p1.value2 = v; 
        return *this; 
    }

    // void print_this() {
    //     cout << this << endl; 
    // }

    // Builder& return_this(int value) {
    //     // p1.value2 = value; 
    //     return *this; 
    // }
};

Builder Person::create(int v1) {
    printf("create()\n");
    return Builder{v1};
}

int main() 
{
    Person p = Person::create(3).updateValue2(5);

    // Builder& b = 

    // A a; 

    // a.print_this(); 

    // A 
    // // B& ref = A::return_this(); 
    // // ref.print_this(); 

    // printf("a's address: %d\n", &a); 
    // printf("ref's address: %d\n", ref.value1);

    return 0; 
}