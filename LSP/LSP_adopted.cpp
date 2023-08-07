#include <iostream>
#include <assert.h>

using namespace std; 

struct Shape {
    virtual uint32_t area() const = 0; 
};

struct Rectangle :Shape {
    Rectangle(const uint32_t width, const uint32_t height) : m_width{width}, m_height{height} {} 

    uint32_t get_width() const { return m_width; } 
    uint32_t get_height() const { return m_height; } 

    virtual void set_width(const uint32_t width) { this->m_width = width; } 
    virtual void set_height(const uint32_t height) { this->m_height = height; } 

    uint32_t area() const override { return m_width * m_height; } 

private: 
    uint32_t m_width, m_height; 
};

struct Square : Shape { 
    Square(uint32_t size) : m_size(size) {} 

    uint32_t get_width() const { return m_size; } 
    uint32_t get_height() const { return m_size; } 
    
    void set_size(const uint32_t size) { this->m_size = size; } 
    uint32_t area() const override { return m_size * m_size; }

private: 
    uint32_t m_size; 
};

void process(Shape &s) {
    cout << s.area() << endl; 

}

int main() 
{
    Rectangle r{5, 5}; 
    process(r); 
    Square s{5}; 
    process(s); 

    return EXIT_SUCCESS;
}
