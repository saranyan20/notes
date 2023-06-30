#include <iostream>
#include "queue.h"

using namespace std;

class Tree{
    public:
        Node* root;
        Tree();
        ~Tree();
        void Create();
        void PreOrder(Node *p);
        void InOrder(Node *p);
        void PostOrder(Node *p);
        void LevelOrder(Node *p);
        int NodeCount(Node *p);
        int Height(Node *p);
        int LeafNodeCount(Node *p);
};

Tree::Tree(){
    root = NULL;
}

Tree::~Tree(){
    delete root;
}

void Tree::Create(){
    int x;
    Queue q(100);
    Node *p, *t;
    cout << "Enter the Root Node: ";
    cin >> x;
    root  = new Node;
    root->data = x;
    root->Lchild = root->Rchild = NULL;
    q.Enqueue(root);

    while(!q.isEmpty()){
        p = q.Dequeue();

        cout << "Enter the Left Child of " << p->data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->Lchild = t->Rchild = NULL;
            p->Lchild = t;
            q.Enqueue(t);
        }

        cout << "Enter the Right Child of " << p->data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->Lchild = t->Rchild = NULL;
            p->Rchild = t;
            q.Enqueue(t);
        }
    }
}

void Tree::PreOrder(Node *p){
    if(p){
        cout << p->data << " ";
        PreOrder(p->Lchild);
        PreOrder(p->Rchild);
    }
}

void Tree::InOrder(Node *p){
    if(p){
        InOrder(p->Lchild);
        cout << p->data << " ";
        InOrder(p->Rchild);
    }
}

void Tree::PostOrder(Node *p){
    if(p){
        PostOrder(p->Lchild);
        PostOrder(p->Rchild);
        cout << p->data << " ";
    }
}

void Tree::LevelOrder(Node *p){
    cout << root->data<< " ";
    Queue q(100);
    q.Enqueue(root);
    while(!q.isEmpty()){
        p = q.Dequeue();

        if(p->Lchild){
            cout << p->Lchild->data << " ";
            q.Enqueue(p->Lchild);
        }
        if(p->Rchild){
            cout << p->Rchild->data << " ";
            q.Enqueue(p->Rchild);
        }
    }
}

int Tree::NodeCount(Node *p){
    if(p)
        return NodeCount(p->Lchild) + NodeCount(p->Rchild) + 1;
    return 0;
}

int Tree::Height(Node *p){
    int x,y;
    if(p){
        x = Height(p->Lchild);
        y = Height(p->Rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

int Tree::LeafNodeCount(Node *p){
    int x,y;
    if(p){
        x = LeafNodeCount(p->Lchild);
        y = LeafNodeCount(p->Rchild);
        if(p->Lchild == NULL && p->Rchild == NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}


int main(){
    Tree t;
    t.Create();
    cout << "PreOrder: ";
    t.PreOrder(t.root);
    cout << endl << "InOrder: ";
    t.InOrder(t.root);
    cout << endl << "PostOrder: ";
    t.PostOrder(t.root);
    cout << endl << "LevelOrder: ";
    t.LevelOrder(t.root);
    cout << end << "Node Count: " << t.NodeCount(t.root);
    cout << end << "Leaf Node Count: " << t.LeafNodeCount(t.root);
    cout << end << "Height: " << t.Height(t.root);

}









