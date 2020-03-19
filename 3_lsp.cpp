#include <iostream>

using namespace std;

class Rectangulo {
protected:
    int width, height;
public:
    Rectangulo(int width, int height) : width(width), height(height) {}

    int getWidth() const { return width; }

    virtual void setWidth(int width) { Rectangulo::width = width; }

    int getHeight() const { return height; }

    virtual void setHeight(int height) { Rectangulo::height = height; }

    int area() {
        return width * height;
    }
};

class Cuadrado : public Rectangulo {
public:
    Cuadrado(int width) : Rectangulo(width, width) {}

    void setWidth(int width) override {
        this->height = this->width = width;
    }

    void setHeight(int height) override {
        this->height = this->width = height;
    }
};

class Rect_Factory{
    Rectangulo new_Rectangulo(int w, int h);
    Rectangulo new_Cuadrado(int w);
};

void test(Rectangulo &r) {
    r.setWidth(10);
    int w = r.getWidth();

    r.setHeight(5);
    int h = r.getHeight();

    cout << w << " " << h << endl;
    cout << r.area() << " " << w * h << endl;
}

int main() {
    Rectangulo r(3, 5);
    Cuadrado c(5);


    test(r);
    test(c);
    return 0;
}
