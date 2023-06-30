#include <iostream>

using namespace std;

struct Node {
    char data;
    struct Node *next;
};

Node* push(Node *top, char x){
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

Node* pop (Node *top){
    Node *p = top;
    if(top == NULL)
        return 0;
    else {
        p = top;
        top = top->next;
        delete p;
    }
    return top;
}

int isBalanced(Node *top, char *exp){
    for(int i=0 ; exp[i]!='\0' ; i++){
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            top = push(top,exp[i]);
        else if(exp[i] == ']'){
            if(top == NULL || top->data != '[')
                return 0;
            top = pop(top);
        }
        else if(exp[i] == '}'){
            if(top == NULL || top->data != '{')
                return 0;
            top = pop(top);
        }
        else if(exp[i] == ')'){
            if(top == NULL || top->data != '(')
                return 0;
            top = pop(top);
        }
    }
    return top?0:1;
}



int main()
{
    struct Node *top = NULL;
    char *exp = "{(a+b)+[c+d]}";


    if(isBalanced(top,exp) == 1)
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
