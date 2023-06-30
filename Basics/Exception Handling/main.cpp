#include <iostream>
using namespace std;

class MyException1
{

};

class MyException2:public MyException1
{

};

int divide(int a, int b) throw (MyException1)
{
    if(b == 0)
        throw MyException1();
    return a/b;
}

int main()
{
    int x=10,y=0,z;
    try
    {
        z = divide(x,y);
        cout << z << endl;
    }
    catch(MyException2 e)
    {
        cout << "Error2: ";
    }
    catch(MyException1 e)
    {
        cout << "Error1: ";
    }
    catch(...)
    {
        cout << "Unknown Error!!";
    }
    cout << endl << "Bye!!";
}
