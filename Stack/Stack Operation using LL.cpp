#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

Node* push(Node *top, int x){
    Node *t = new Node;
    if(t == NULL)
        cout << "Overflow" << endl;
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
    return top;
}

Node* pop(Node *top){
    int x = -1;
    Node *t = top;
    if(top == NULL)
        cout << "Underflow" << endl;
    else {
        top = top->next;
        x = t->data;
        delete t;
    }
    cout << x << endl;
    return top;
}

void peek(Node *p, int index){
    for(int i=1 ; i<index ; i++){
        p = p->next;
    }
    cout << p->data;
}

void display(Node *p){
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    struct Node *top = NULL;
    top = push(top,20);
    top = push(top,30);
    top = push(top,40);
    top = push(top,50);

    display(top);
    peek(top,1);
}
