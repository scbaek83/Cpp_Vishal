#include <iostream> 
#include <ostream>
#include <memory>
#include <map>
#include <functional>

#define _USE_MATH_DEFINES       // for using M_PI_4
#include <math.h>

using namespace std; 

// enum class PointType{ cartesian, polar }; 
enum class PointType { Point2D, Point3D };

struct Point {
    virtual ~Point() = default; 
    virtual unique_ptr<Point> create() = 0; 
    virtual unique_ptr<Point> clone() = 0; 
}; 

struct Point2D : Point {
    unique_ptr<Point> create() { return make_unique<Point2D>(); } 
    unique_ptr<Point> clone() { return make_unique<Point2D>(*this); }
};

struct Point3D : Point {
    unique_ptr<Point> create() { return make_unique<Point3D>(); } 
    unique_ptr<Point> clone() { return make_unique<Point3D>(*this); } 
};

void who_am_i(Point *who) {
    auto new_who = who->create(); 
    auto duplicate_who = who->clone(); 

    delete who; 
}

class PointFunctionalFactory { 
    map<PointType, function<unique_ptr<Point>() >> m_factories; 

public:
    PointFunctionalFactory() {
        m_factories[PointType::Point2D] = [] { return make_unique<Point2D>(); }; 
        m_factories[PointType::Point3D] = [] { return make_unique<Point3D>(); }; 
    }
    unique_ptr<Point> create(PointType type) { return m_factories[type](); } 
};

int main() 

{
    PointFunctionalFactory pf; 
    auto p2D = pf.create(PointType::Point2D);

    return EXIT_SUCCESS; 
}