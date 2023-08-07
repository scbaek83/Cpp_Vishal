#include <iostream> 
#include <ostream>

#define _USE_MATH_DEFINES 
#include <math.h>

using namespace std; 

enum class PointType{ cartesian, polar }; 

class Point {
    float m_x; 
    float m_y; 
    PointType m_type; 

    // Private constructor, so that object can't be created directly 
    Point(const float x, const float y, PointType t) : m_x{x}, m_y{y}, m_type{t} {} 

public: 
    friend ostream &operator<<(ostream &os, const Point &obj) {
        return os << "s: " << obj.m_x << " : " << obj.m_y; 
    }

    static Point NewCartesian(float x, float y) {
        return {x, y, PointType::cartesian}; 
    }

    static Point NewPolar(float a, float b) {
        return {a * cos(b), a * sin(b), PointType::polar}; 
    }

    friend class PointFactory; 
};

class PointFactory {
public:
    static Point NewCartesian(float x, float y) {
        return { x, y }; 
    }
    static Point NewPolar(float r, float theta) {
        return { r*cos(theta), r*sin(theta) };
    }
};

int main() 
{
    // Point pp{1, 2};      will not work 
    auto p = Point::NewPolar(5, M_PI_4); 
    cout << p << endl; 

    return EXIT_SUCCESS; 
}