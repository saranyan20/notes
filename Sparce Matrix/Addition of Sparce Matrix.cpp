#include<iostream>
using namespace std;

struct Element {
    int i;
    int j;
    int x;
};
struct Sparse {
    int m;
    int n;
    int num;
    struct Element *e;
};

void Create(struct Sparse *s){
    cout << "M:";
    cin >> s->m;
    cout << "N:";
    cin >> s->n;
    cout << "Num:";
    cin >> s->num;
    s->e = new Element[s->num];
    cout << "Enter the non-zero elements:" << endl;
    for(int i=0 ; i<s->num ; i++){
        cin >> s->e[i].i >> s->e[i].j >> s->e[i].x;
    }
}

Sparse * Add(struct Sparse *s1 ,struct Sparse *s2){
    int i=0,j=0,k=0;
    struct Sparse *sum;
    sum = new Sparse;
    sum->m = s1->m;
    sum->n = s1->n;
    sum->e = new Element[s1->num + s2->num];
    while(i<s1->num && j<s2->num){
        if(s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++];
        else if(s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];
        else{
            if(s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];
            else if(s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];
            else{
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    for(;i<s1->num ; i++)
        sum->e[k++] = s1->e[i++];
    for(;j<s2->num ; j++)
        sum->e[k++] = s2->e[j++];
    sum->num = k;
    return sum;
}

void Display(struct Sparse s){
    int k=0;
    for(int i=0 ; i<s.m ; i++){
        for(int j=0 ; j<s.n ; j++){
            if(i == s.e[k].i && j == s.e[k].j)
                cout << s.e[k++].x << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}


int  main(){
    struct Sparse s1,s2,*s3;
    Create(&s1);
    Create(&s2);
    s3 = Add(&s1,&s2);
    Display(*s3);
    return 0;
}
