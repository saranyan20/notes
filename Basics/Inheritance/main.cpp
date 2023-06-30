#include <iostream>

using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;
public:
    Rectangle(int length, int breadth);
    void setLength(int length);
    void setBreadth(int breadth);
    int getLength();
    int getBreadth();
    int area();
    int isSquare(int length, int breadth);
};

class Cuboid:public Rectangle
{
private:
    int height;
public:
    Cuboid(int length, int breadth, int height);
    void setHeight(int height);
    int getHeight();
    int volume();
};

int main()
{
    Cuboid c(10,20,30);
    cout << c.area() << endl << c.volume();
    return 0;
}

// Rectangle Class
Rectangle::Rectangle(int length, int breadth)
{
    setLength(length);
    setBreadth(breadth);
}
void Rectangle::setLength(int length)
{
    this->length = length;
}
void Rectangle::setBreadth(int breadth)
{
    this->breadth = breadth;
}
int Rectangle::getLength()
{
    return length;
}
int Rectangle::getBreadth()
{
    return breadth;
}
int Rectangle::area()
{
    return length*breadth;
}
int Rectangle::isSquare(int length, int breadth)
{
    return length==breadth ?1:0;
}

// Cuboid Class
Cuboid::Cuboid(int length, int breadth, int height):Rectangle(length,breadth)
{
    setHeight(height);
}
void Cuboid::setHeight(int height)
{
    this->height = height;
}
int Cuboid::getHeight()
{
    return height;
}
int Cuboid::volume()
{
    return getLength() * getBreadth() * getHeight();
}
