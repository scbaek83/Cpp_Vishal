#include <iostream> 
#include <memory> 

using namespace std; 

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