#include<iostream>
using namespace std;

struct Node{
    char data;
    struct Node *next;
};

Node * Push(Node *top, char x){
    Node *t = new Node;
    if(t == NULL)
        cout << "Overflow!!";
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
    return top;
}

Node * Pop(Node *top){
    Node *t = top;
    int x = -1;
    if(top == NULL)
        cout << "Underflow!!";
    else{
        top = top->next;
        x = t->data;
        delete t;
    }
    return top;
}

char isBalanced(Node *top, char *e){
    for(int i=0 ; e[i]!='\0' ; i++){
        if(e[i] == '(' || e[i] == '{' || e[i] == '[')
            top = Push(top, e[i]);
        else if(e[i] == ')'){
            if(top->data == '(')
                top = Pop(top);
            else if(top == NULL) return 0;
        }
        else if(e[i] == ']'){
            if(top->data == '[')
                top = Pop(top);
            else if(top == NULL) return 0;
        }
        else if(e[i] == '}'){
            if(top->data == '{')
                top = Pop(top);
            else if(top == NULL) return 0;
        }
    }
    if(top == NULL)
        return 1;
    else
        return 0;
}

void Display(Node *p){
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
}

int main(){
    struct Node *top = NULL;
    char *exp = "{{(a+b)*[a-b]}";
    if(isBalanced(top,exp) == 1)
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
