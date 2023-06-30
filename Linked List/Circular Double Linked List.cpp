#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}*head = NULL;

void Create(int A[], int n){
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->prev = head;
    head->next = head;
    last = head;
    for(int i=1 ; i<n ; i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

int length(){
    Node *p = head;
    int len = 0;
    do{
        len++;
        p = p->next;
    } while(p!=head);
    return len;
}

void Insert(struct Node *p,int index, int x){
    Node *t;
    if(index < 0 || index > length())
        return;
    if(index == 0){
        t = new Node;
        t->data = x;
        t->prev = head->prev;
        head->prev->next = t;
        t->next = head;
        head->prev = t;
        head = t;
    }
    else {
        t = new Node;
        t->data = x;
        for(int i=0 ; i<index-1 ; i++){
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
    }
}

void Display(){
    Node *p = head;
    do{
        cout << p->data << " ";
        p = p->next;
    }while(p!=head);
}


int main(){
    int A[] = {10,20,30,40,50};
    Create(A,5);
//    Display(head);
//    cout << endl;
//    Insert(head,0,6);
    Display();
    cout << endl << MiddleNode();

}
