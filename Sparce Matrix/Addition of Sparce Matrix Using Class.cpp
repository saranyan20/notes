#include<iostream>
using namespace std;

class Element {
public:
    int i;
    int j;
    int x;
};
class Sparse {
private:
    int m;
    int n;
    int num;
    Element *e;
public:
    Sparse(int m, int n, int num){
        this->m = m;
        this->n = n;
        this->num = num;
        e = new Element[this->num];
    }
    ~Sparse(){
        delete [] e;
    }

    Sparse operator+(Sparse &s);
    friend istream & operator>>(istream &is, Sparse &s);
    friend ostream & operator<<(ostream &os, Sparse &s);

};

istream & operator>>(istream &is, Sparse &s){
    cout << "Enter the non-zero elements:" << endl;
    for(int i=0 ; i<s.num ; i++){
        cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;
    }
    return is;
}

Sparse Sparse::operator+(Sparse &s){
    int i=0,j=0,k=0;
    struct Sparse *sum;
    sum = new Sparse(m,n,num+s.num);
    while(i<num && j<s.num){
        if(e[i].i < s.e[j].i)
            sum->e[k++] = e[i++];
        else if(e[i].i > s.e[j].i)
            sum->e[k++] = s.e[j++];
        else{
            if(e[i].j < s.e[j].j)
                sum->e[k++] = s.e[i++];
            else if(e[i].j > s.e[j].j)
                sum->e[k++] = s.e[j++];
            else{
                sum->e[k] = e[i];
                sum->e[k++].x = e[i++].x + s.e[j++].x;
            }
        }
    }
    for(;i<num ; i++)
        sum->e[k++] = e[i++];
    for(;j<s.num ; j++)
        sum->e[k++] = s.e[j++];
    sum->num = k;
    return *sum;
}

ostream & operator<<(ostream &os, Sparse &s){
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
    return os;
}


int  main(){
    Sparse s1(3,3,3);
    Sparse s2(3,3,3);

    cin>>s1;
    cin>>s2;

    Sparse sum = s1+s2;
    cout << sum;
}

