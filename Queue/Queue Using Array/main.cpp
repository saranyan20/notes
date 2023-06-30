#include <iostream>
using namespace std;

class Queue {

    private:
        int data;
        int front;
        int rear;
        int *arr;

    public:
        int Size;
        Queue();
        ~Queue();
        int Enqueue(int x);
        int Dequeue();
        void Display();
};

Queue::Queue(){
    arr = new int[10];
    rear = -1;
    front = -1;
}

Queue::~Queue(){
    delete [] arr;
}

int Queue::Enqueue(int x){
    if(rear == Size-1)
        return 0;
    arr[++rear] = x;
    return 1;
}

int Queue::Dequeue(){
    int x=-1;
    if(rear == front)
        return 0;
    x = arr[++front];
    return x;
}

void Queue::Display(){
    for(int i=front+1 ; i<=rear ; i++)
        cout << arr[i] << " ";
}

int main(){
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);


    q.Display();
}

