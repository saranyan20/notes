#include <iostream>

using namespace std;

// Interface
class Shape
{
    public:
        virtual void area() = 0;
        virtual void perimeter() = 0;
};

// Classes
class Rectangle:public Shape
{
    private:
        int l;
        int b;
    public:
        Rectangle(int l, int b){ this->l = l; this->b = b;}
        void area() { cout << "Area of Rectangle " << l*b << endl; }
        void perimeter() { cout << "Perimeter of Rectangle " << 2*(l+b) << endl << endl; }
};

class Circle:public Shape
{
    private:
        float r;
    public:
        Circle(int r){ this->r = r; }
        void area() { cout << "Area of Circle " <<  3.14*r*r << endl; }
        void perimeter() { cout << "Perimeter of Circle " << 2*3.14*r << endl; }
};
int main()
{
    Shape *s;
    s = new Rectangle(10,20);
    s->area();
    s->perimeter();

    s = new Circle(4);
    s->area();
    s->perimeter();
    return 0;
}
