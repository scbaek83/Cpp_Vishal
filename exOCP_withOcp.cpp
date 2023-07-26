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

template <typename T> 
struct Specification {
    virtual ~Specification() = default; 
    virtual bool is_satisfied(T *item) const = 0; 
};

struct ColorSpecification : Specification<Product> {
    COLOR e_color; 
    ColorSpecification(COLOR e_color) : e_color(e_color) {} 
    bool is_satisfied(Product *item) const { return item->m_color == e_color; }
};

struct SizeSpecification : Specification<Product> {
    SIZE e_size; 
    SizeSpecification(SIZE e_size) : e_size(e_size) {} 
    bool is_satisfied(Product *item) const { return item->m_size == e_size; }
};

template <typename T> 
struct Filter {
    virtual vector<T *> filter(vector<T *> items, const Specification<T> &spec) = 0; 
};

struct BetterFilter : Filter<Product> {
    vector<Product *> filter(vector<Product *> items, const Specification<Product> &spec) {
        vector<Product *> result; 
        for (auto &p : items) 
            if (spec.is_satisfied(p))
                result.push_back(p); 
        return result; 
    }
};

int main(void) 
{
    const Items all{
        new Product{"Apple", COLOR::GREEN, SIZE::SMALL}, 
        new Product{"Tree", COLOR::GREEN, SIZE::LARGE}, 
        new Product{"House", COLOR::BLUE, SIZE::LARGE}
    }; 

    BetterFilter bf; 
    for (auto &x : bf.filter(all, ColorSpecification(COLOR::GREEN))) 
        cout << x->m_name << " is green\n"; 

    return EXIT_SUCCESS; 
}
