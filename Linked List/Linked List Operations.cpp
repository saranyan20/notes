#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class List {
private:
    Node *first;

public:
    List();
    List(int A[], int n);
    ~List();
    void Display();
    int Length();
    void Insert(int index, int x);
    int Delete(int index);
    int MiddleNode();
};

List::List(){
    first = NULL;
}

List::List(int A[], int n){
    Node *last, *t;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i=1 ; i<n ; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}


List::~List(){
    Node *p = first;
    while(first){
        first=first->next;
        delete p;
        p=first;
    }
}

void List::Display(){
    if(first == NULL){
        cout << "List Empty!!";
    }
    Node *p = first;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
}

int List::Length(){
    Node *p = first;
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

void List::Insert(int index, int x){
    Node *p = first;
    if(index < 0 || index > Length())
        return;
    Node *t = new Node;
    t->data = x;
    t->next = NULL;
    if(index == 0){
        t->next = first;
        first = t;
    }
    else {
        for(int i=0 ; i<index-1 ; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = p;
    }
}

int List::Delete(int index){
    if(index < 0 || index > Length())
        return 0;
    Node *p = first, *q = NULL;
    if(index == 1){
        first = first->next;
        delete p;
    }
    else {
        for(int i=0 ; i<index-1 ; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
    }
    return 0;
}

int List::MiddleNode(){
    Node *p = first;
    Node *q = first;
    while(q){
        q = q->next;
        if(q)
            q = q->next;
        if(q)
            p = p->next;
    }
    return p->data;
}


int main(){
    int A[] = {10,20,30,40,50,60,70};
    List l(A,7);
    l.Display();
    cout << endl << l.MiddleNode();
}
