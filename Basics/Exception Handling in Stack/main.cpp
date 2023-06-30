#include <iostream>

using namespace std;

class StackUnderFlow : public exception {};
class StackOverFlow : public exception {};

class Stack
{
    private:
        int *arr;
        int top = -1;
        int Size;
    public:
        Stack(int Size){
            this->Size = Size;
            arr = new int[Size];
        }
        int push(int x);
        int pop();
        void display();
};


int main()
{
    Stack s(5);
    try
    {
        cout << s.push(1) << endl;
        cout << s.push(2) << endl;
        cout << s.push(3) << endl;
        cout << s.push(4) << endl;
        cout << s.push(5) << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
    }
    catch(StackOverFlow e)
    {
        cout << "Stack Over Flow";
    }
    catch(StackUnderFlow e)
    {
        cout << "Stack Under Flow";
    }
    return 0;
}

int Stack::push(int x)
{
    if(top == Size-1)
        throw StackOverFlow();
    arr[++top] = x;
    return 1;
}

int Stack::pop()
{
    int x = -1;
    if(top == -1)
        throw StackUnderFlow();
    x = arr[top--];
    return x;
}

void Stack::display()
{
    for(int i=top ; i>=0 ; i--)
    {
        cout << arr[i] << " ";
    }
}
