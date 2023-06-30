#include <iostream>
#include <math.h>
using namespace std;

struct Node{
    int coeff;
    int exp;
    struct Node *next;
};

Node* Create(int n){
    Node *head = NULL, *p, *t;
    p = head;
    for(int i=0 ; i<n ; i++){
        t = new Node;
        t->next = NULL;
        cin >> t->coeff >> t->exp;
        if(i == 0){
            head = t;
            p = t;
        }
        else {
            p->next = t;
            p = t;
        }
    }
    return head;
}

int Solve(Node *p, int x){
    int sum = 0;
    while(p){
        sum += p->coeff * pow(x,p->exp);
        p = p->next;
    }
    return sum;
}

Node* Sum(Node *x, Node *y){
    Node *sum_head = NULL, *t;
    Node *p = sum_head;
    while(x && y){
        t = new Node;
        t->coeff = x->coeff + y->coeff;
        t->exp = x->exp;
        t->next = NULL;
        if(sum_head == NULL){
            sum_head = t;
            p = t;
        }
        else {
            p->next = t;
            p = t;
        }
        x = x->next;
        y = y->next;
    }
    return sum_head;
}

void Display(Node *p){
    while(p){
        if(!p->next)
            cout << p->coeff << "(x^" << p->exp << ")";
        else
            cout << p->coeff << "(x^" << p->exp << ") + ";
        p = p->next;
    }
}

int main(){
    int n;
    Node *head1, *head2, *head3;
    cout << "N:";
    cin >> n;
    head1 = Create(n);
    Display(head1);
    cout << endl;
    head2 = Create(n);
    Display(head2);
    cout << endl;
    head3 = Sum(head1, head2);
    cout << "Result:" << endl;
    Display(head3);
}
