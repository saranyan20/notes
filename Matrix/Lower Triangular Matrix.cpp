#include<iostream>
using namespace std;

struct Matrix{
    int *a;
    int n;
};

void set(struct Matrix *m){
    if(i>=j){
        m->a[i*(i-1)/2 + (j-1)] = x;
    }
}

int get(struct Matrix m){
    if(i>=j){
        return m.a[i*i(i-1)/2 + (j-1)];
    } else {
        return 0;
    }
}

void display(struct Matrix m){
    for(int i=0 ; i<m.n ; i++){
        for(int j=0 ; j<m.n ; j++){
            a[]
        }
    }
}

int main(){
    struct Matrix m;
    int x;
    cout << "Enter the limit";
    cin << m.n;

    m.a = new int;

    cout << "Enter the elements";
    for(int i=0 ; i<m.n ; i++){
        for(int j=0 ; j<m.n ; j++){
            cin >> x;
            set(&m,i,j,x);
        }
    }
}
