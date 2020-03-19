#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

enum class Color {
    rojo, verde, azul
};
enum class Size {
    chico, mediano, grande
};

struct Product {
    string name;
    Color color;
    Size size;
};

class ProductFilter {
public:
    vector<Product *> by_color(vector<Product *> items, Color color) {
        vector<Product *> res;
        for (auto i: items) {
            if (i->color == color)
                res.push_back(i);
        }
        return res;
    }

    vector<Product *> by_size(vector<Product *> items, Size size) {
        vector<Product *> res;
        for (auto i: items) {
            if (i->size == size)
                res.push_back(i);
        }
        return res;
    }

    vector<Product *> by_size_and_color(vector<Product *> items, Size size, Color color) {
        vector<Product *> res;
        for (auto i: items) {
            if (i->size == size && i->color == color)
                res.push_back(i);
        }
        return res;
    }
};

template<typename T>
class Specification {
public:
    virtual bool is_satisfied(T *item) = 0;
};

template<typename T>
class Filter {
public:
    virtual vector<T *> filter(vector<T *> items, Specification<T> &spec) = 0;
};

class ColorSpec : public Specification<Product> {
    Color color;
public:
    ColorSpec(Color color) : color(color) {}

    bool is_satisfied(Product *item) override {
        return item->color == color;
    }
};

class SizeSpec: public Specification<Product>{
    Size size;
public:
    SizeSpec(Size size) : size(size) {}

    bool is_satisfied(Product *item) override {
        return item->size == size;
    }
};

template<typename T>
class AndSpec: public Specification<T>{
    Specification<T>& primera;
    Specification<T>& segunda;
public:
    AndSpec(Specification<T> &primera, Specification<T> &segunda) : primera(primera), segunda(segunda) {}

    bool is_satisfied(T *item) override {
        return primera.is_satisfied(item) && segunda.is_satisfied(item);
    }
};


class BetterFilter : Filter<Product> {
public:
    vector<Product *> filter(vector<Product *> items, Specification<Product> &spec) override {
        vector<Product *> res;
        for (auto i: items) {
            if (spec.is_satisfied(i))
                res.push_back(i);
        }
        return res;
    }
};


int main() {
    Product manzana{"Manzana", Color::rojo, Size::chico};
    Product frutilla{"Frutilla", Color::rojo, Size::chico};
    Product sandia{"Sandia", Color::verde, Size::chico};
    Product pomelo{"Pomelo", Color::rojo, Size::mediano};

    vector<Product *> productos{&manzana, &sandia, &pomelo, &frutilla};

    for (auto p: productos) {
        cout << p->name << endl;
    }
    cout << endl << endl;

    BetterFilter bf;
    ColorSpec sp_rojo(Color::rojo);
    SizeSpec sp_chicos(Size::chico);

    AndSpec<Product> sp_rojoYchico(sp_rojo, sp_chicos);


    vector<Product *> rojos;

    rojos = bf.filter(productos, sp_rojoYchico);

    for (auto p: rojos) {
        cout << "Rojo: " << p->name << endl;
    }
    return 0;
}
