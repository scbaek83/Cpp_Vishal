#include <iostream> 
#include <ostream>

#define _USE_MATH_DEFINES 
#include <math.h>

using namespace std; 

enum class PointType{ cartesian, polar }; 

class Point {
    float m_x; 
    float m_y; 
    
    Point(float x, float y) : m_x(x), m_y(y) {} 

public:
    struct Factory {
        static Point NewCartesian(float x, float y) { return { x, y }; }
        static Point NewPolar(float r, float theta) { return { r*cos(theta), r*sin(theta) }; }
    };
};

int main() 
{
    // Point pp{1, 2};      will not work 
    // auto p = Point::NewPolar(5, M_PI_4); 
    // cout << p << endl; 

    auto p = Point::Factory::NewCartesian(2, 3); 
    // cout << p.m_x << p.m_y <<endl; 

    return EXIT_SUCCESS; 
}