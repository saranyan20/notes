#include <iostream>
using namespace std;

class Queue {

    private:
        int data;
        int front;
        int rear;
        int *arr;
        int Size;
    public:
        Queue();
        ~Queue();
        int Enqueue(int x);
        int Dequeue();
        void Display();
};

Queue::Queue(){
    Size = 5;
    arr = new int[Size];
    rear = -1;
    front = -1;
}

Queue::~Queue(){
    delete [] arr;
}

int Queue::Enqueue(int x){
    if((rear+1)%Size == front)
        return 0;
    rear = (rear+1)%Size;
    arr[rear] = x;
    return 1;
}

int Queue::Dequeue(){
    int x=-1;
    if(rear == front)
        return 0;
    front  = (front+1)%Size;
    x = arr[front];
    return x;
}

void Queue::Display(){
    int i = (front+1)%Size;
    do{
        cout << arr[i] << " ";
        i = (i+1)%Size;
    } while(i != rear+1%Size);
}

int main(){
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    q.Dequeue();
    q.Dequeue();
    q.Dequeue();

    q.Enqueue(60);
    q.Enqueue(70);

    q.Display();
}

