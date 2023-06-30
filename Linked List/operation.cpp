#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void Insert(struct Node *p, int x, int index){
    struct Node *t = new Node;
    t -> data = x;
    t -> next = NULL;
    if(index < 0)
        return ;
    else if(index == 0){
        t -> next = first;
        first = t;
    }
    else {
        for(int i=0 ; i<index-1 ; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int index){
    Node *q;
    int x = -1;
    if(index < 1)
        return -1;
    if(index == 1){
        x = first->data;
        p = first;
        first = first -> next;
        delete p;
    }
    else {
        q = NULL;
        for(int i=0 ; i<index-1 && p ; i++){
            q = p;
            p = p->next;
        }
        if(p){
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    return x;
}

void RemoveDuplicate(struct Node *p){
    struct Node *q = p->next;
    while(q!=NULL){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int Display(struct Node *p){
    if(p){
        cout << p->data << " ";
        return Display(p->next);
    }
    return 0;
}


int main(){
    Insert(first,10,0);
    Insert(first,20,1);
    Insert(first,30,2);
    Insert(first,40,3);
    Insert(first,50,4);
    Insert(first,50,5);
    Insert(first,10,0);

    Display(first);
    cout << endl;
    RemoveDuplicate(first);
    Display(first);

//    Display(first);
//    cout << endl << "Deleted Element: " << Delete(first,0) << endl;
//    Display(first);


}
