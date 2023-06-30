#include <iostream>

using namespace std;

struct Node {
    struct Node *next;
    int data;
};

Node * push(Node *top, int x){
    Node *t = new Node;
    if(t == NULL)
        return 0;
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
    return top;
}

Node * pop(Node *top){
    int x = -1;
    Node *p = top;
    if(top == NULL)
        return 0;
    else {
        x = top->data;
        top = top->next;
        delete p;
    }
    return top;
}

void display(Node *p){
    while(p){
        cout << p->data << endl;
        p = p->next;
    }
}

int main()
{
    struct Node *top = NULL;
    top = push(top,40);
    top = push(top,30);
    top = push(top,20);
    top = push(top,10);

    top = pop(top);

    display(top);

    return 0;
}
