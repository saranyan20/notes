#include <iostream>
#include <string.h>

using namespace std;

struct Node {
    int data;
    Node *next;
}*top = NULL;

int push(int x){
    Node *t = new Node;
    if(t == NULL)
        return 0;
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
    return 1;
}

char pop(){
    char x;
    Node *p = top;
    if(top == NULL)
        return 0;
    else {
        p = top;
        x = top->data;
        top = top->next;
        delete p;
    }
    return x;
}

int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    return 1;
}

int pre(char ch){
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    return 0;
}

char* toPostFix(char *inFix){
    int len = strlen(inFix);
    char *postFix = new char[len];
    int j=0, i=0;
    while(inFix[i] != '\0'){
        if(isOperand(inFix[i]))
            postFix[j++] = inFix[i++];
        else{
            if(pre(inFix[i]) > pre(top->data))
                push(inFix[i++]);
            else{
                postFix[j++] = pop();
            }
        }
    }
    while(top!=NULL)
        postFix[j++] = pop();
    postFix[j] = '\0';
    return postFix;
}



int main()
{
    char *inFix = "a+b*c-d/e";
    push('#');
    cout << toPostFix(inFix);

}
