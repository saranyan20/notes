#include <iostream>

using namespace std;

class Rational{
    private:
        int x;
        int y;
    public:
        Rational();
        Rational(int x, int y);
        ~Rational();
        friend Rational operator*(Rational r1, Rational r2);
        friend ostream& operator<<(ostream &out, Rational &r);
};

Rational::Rational(){
    x=0;
    y=0;
}
Rational::Rational(int x, int y){
    this->x = x;
    this->y = y;
}
Rational::~Rational(){
    cout << "Memory Cleared!!";
}
Rational operator*(Rational r1, Rational r2){
    Rational t;
    t.x = r1.x * r2.x;
    t.y = r1.y * r2.y;
    return t;
}
ostream& operator<<(ostream &out, Rational &r){
    out << r.x << "/" << r.y;
    return out;
}

int main()
{
    Rational r1(2,5),r2(3,6),r3;
    r3 = r1*r2;
    cout << r3;
    return 0;
}
