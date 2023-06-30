#include <iostream>
#include <math.h>
using namespace std;

struct Element{
    int c;
    int e;
};
struct Polynomial{
    int n;
    struct Element *e;
};

void create(struct Polynomial *p){
    cout << "N:";
    cin >> p->n;
    p->e = new Element[p->n];
    for(int i=0 ; i<p->n ; i++){
        cin >> p->e[i].c >> p->e[i].e;
    }
}

Polynomial * add(struct Polynomial *p1, struct Polynomial *p2){
    int i=0,j=0,k=0;
    struct Polynomial *sum = new Polynomial;
    sum->e = new Element[p1->n + p2->n];
    while(i<p1->n && j<p2->n){
        if(p1->e[i].e > p2->e[j].e)
            sum->e[k++] = p1->e[i++];
        else if(p1->e[i].e < p2->e[j].e)
            sum->e[k++] = p2->e[j++];
        else{
            sum->e[k] = p1->e[i];
            sum->e[k++].c = p1->e[i++].c + p2->e[j++].c;
        }
    }
    for(; i<p1->n ;)
        sum->e[k++] = p1->e[i++];
    for(; j<p2->n ;)
        sum->e[k++] = p2->e[j++];
    sum->n = k;
    return sum;
}

void display(struct Polynomial p){
    for(int i=0 ; i<p.n ; i++){
        cout << p.e[i].c << "(x^" << p.e[i].e << ")";
        if(i != p.n-1){
            cout << " + ";
        }
    }
    cout << endl;
}

int main(){
    struct Polynomial p1,p2,*s;
    create(&p1);
    create(&p2);
    s = add(&p1,&p2);
    cout << "P1:";
    display(p1);
    cout << "P2:";
    display(p2);
    cout << "SUM:";
    display(*s);



}
