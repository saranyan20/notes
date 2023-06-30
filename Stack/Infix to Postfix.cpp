#include <iostream>
#include <string.h>
using namespace std;

struct Node{
    char data;
    struct Node *next;
}*top = NULL;

Node * Push(char x){
    Node *t = new Node;
    if(t == NULL)
        return 0;
    t->data = x;
    t->next = top;
    top = t;
    return top;
}

char  Pop(){
    Node *t = top;
    int x = -1;
    if(top == NULL)
        return 0;
    top = top->next;
    x = t->data;
    delete t;
    return x;
}

void Display(){
    Node *t = top;
    while(t){
        cout << t->data << " ";
        t = t->next;
    }
}

int isOperand(char exp){
    if(exp == '+' || exp == '-' ||  exp == '*' || exp == '/'){
        return 0;
    }
    return 1;
}

int Prec(char exp){
    if(exp == '+' || exp == '-')
        return 1;
    else if(exp = '*' || exp == '/')
        return 2;
    return 0;
}

char * InfToPost(char *inFix){
    int i=0, j=0;
    char *postFix;
    int len = strlen(inFix);
    postFix = new char[len+2];

    while(inFix[i] != '\0'){
        if(isOperand(inFix[i]))
            postFix[j++] = inFix[i++];
        else {
            if(Prec(inFix[i]) > Prec(top->data))
                Push(inFix[i++]);
            else{
                postFix[j++] = Pop();
            }
        }
    }
    while(top != NULL)
        postFix[j++] = Pop();
    postFix[j] = '\0';
    return postFix;
}

int main(){
    char *inFix = "a+b*c-d/e";
    Push('#');
    char *postFix = InfToPost(inFix);
    cout << postFix;
}
