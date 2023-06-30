#include <iostream>
#include "Queue.h"

using namespace std;

class Tree{

    public:
        Node *root;
        Tree();
//        ~Tree();
        void Create();
        void Preorder(Node* root);
        void Inorder(Node *root);
        void Postorder(Node *root);
};

Tree::Tree(){
    root = NULL;
}

void Tree::Create(){
    int x;
    Node *t, *p;
    Queue q(100);

    cout << "Enter the Root Node:";
    cin >> x;

    root = new Node;
    root->data = x;
    root->lChild = root->rChild = NULL;
    q.Enqueue(root);

    while(!q.isEmpty()){
        p = q.Dequeue();
//      Left Child
        cout << "Enter the Left Child of " << p->data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lChild = t->rChild = NULL;
            p->lChild = t;
            q.Enqueue(t);
        }
//      Right Child
        cout << "Enter the Right Child of " << p->data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->rChild = t->rChild = NULL;
            p->rChild = t;
            q.Enqueue(t);
        }
    }
}

void Tree::Preorder(Node *t){
    if(t!=NULL){
        cout << t->data << " ";
        Preorder(t->lChild);
        Preorder(t->rChild);
    }
}

void Tree::Inorder(Node *t){
    if(t!=NULL){
        Inorder(t->lChild);
        cout << t->data << " ";
        Inorder(t->rChild);
    }
}

void Tree::Postorder(Node *t){
    if(t!=NULL){
        Postorder(t->lChild);
        Postorder(t->rChild);
        cout << t->data << " ";
    }
}

int main(){
    Tree t;
    t.Create();
    t.Preorder(t.root);
    return 0;
}


