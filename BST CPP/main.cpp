#include <iostream>
using namespace std;

class Node {
    public:
        Node *Lchild;
        int data;
        Node *Rchild;
};

class Tree {
    public:
        Node *root;
        Tree();
        ~Tree();
        void Iterative_Insert(int key);
        void Recursive_Insert(int key);
        Node* Iterative_Search(Node *p, int key);
        Node* Recursive_Search(Node *p, int key);
        Node* Delete(Node *p, int key);
        void PreOrder(Node *p);
        int Height(Node *p);
        Node* InPre(Node *p);
        Node* InSucc(Node *p);
};

Tree::Tree(){
    root = NULL;
}

Tree::~Tree(){
    delete root;
}

void Tree::Iterative_Insert(int key){

    Node *p;
    Node *t = root;
    if(root == NULL){
        p = new Node;
        p->data = key;
        p->Lchild = p->Rchild = NULL;
        root = p;
        return ;
    }

    Node *r = NULL;
    while(t){
        r = t;
        if(key == t->data)
            return ;
        else if(key < t->data)
            t = t->Lchild;
        else
            t = t->Rchild;
    }

    p = new Node;
    p->data = key;
    p->Lchild = p->Rchild = NULL;

    if(p->data < r->data)
        r->Lchild = p;
    else
        r->Rchild = p;
}

Node* Tree::Iterative_Search(Node *p, int key){

    if(!p)
        return NULL;
    while(p){
        if(p->data == key)
            return p;
        else if(key < p->data)
            p = p->Lchild;
        else
            p = p->Rchild;
    }
    return NULL;
}

Node* Tree::Recursive_Search(Node *p, int key){
    if(!p)
        return NULL;
    if(p->data == key)
        return p;
    else if(key < p->data)
        return Recursive_Search(p->Lchild,key);
    else
        return Recursive_Search(p->Rchild,key);
}

void Tree::PreOrder(Node *p){
    if(p){
        cout << p->data << " ";
        PreOrder(p->Lchild);
        PreOrder(p->Rchild);
    }
}

int Tree::Height(Node *p){
    int x,y;
    if(!p)
        return NULL;
    x = Height(p->Lchild);
    y = Height(p->Rchild);
    return x>y ?x+1 :y+1;
}

Node* Tree::InPre(Node *p){
    while(p && p->Rchild)
        p = p->Rchild;
    return p;
}

Node* Tree::InSucc(Node *p){
    while(p && p->Lchild)
        p = p->Lchild;
    return p;
}

Node* Tree::Delete(Node *p, int key){
    Node *q;
    if(!p)
        return NULL;
    if(p->Lchild == NULL && p->Rchild == NULL){
        if(root == p)
            return NULL;
        delete p;
        return NULL;
    }

    if(p->data > key)
        p->Lchild = Delete(p->Lchild,key);
    else if(p->data < key)
        p->Rchild = Delete(p->Rchild,key);
    else{
        if(Height(p->Lchild) > Height(p->Rchild)){
            q = InPre(p->Lchild);
            p->data = q->data;
            p->Lchild = Delete(p->Lchild,q->data);
        }
        else{
            q = InSucc(p->Rchild);
            p->data = q->data;
            p->Rchild = Delete(p->Rchild,q->data);
        }
    }

    return p;
}

int main(){
    Tree t;
    t.Iterative_Insert(30);
    t.Iterative_Insert(15);
    t.Iterative_Insert(50);
    t.Iterative_Insert(10);
    t.Iterative_Insert(20);
    t.Iterative_Insert(40);
    t.Iterative_Insert(60);
    t.PreOrder(t.root);
//    cout << endl << t.Iterative_Search(t.root, 10);
//    cout << endl << t.Iterative_Search(t.root, 100);
//    cout << endl << t.Iterative_Search(t.root, 60);
//    cout << endl << t.Recursive_Search(t.root, 10);
//    cout << endl << t.Recursive_Search(t.root, 60);
    cout << endl;
    t.Delete(t.root,30);
    t.PreOrder(t.root);

}
