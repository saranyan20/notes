#include <iostream>
using namespace std;

struct Node{
    int row;
    int col;
    int val;
    struct Node *next;
};


Node* Create(Node* arr[5], int mat[5][6], int m, int n){
    Node *t;
    Node *p;
    for(int i=0 ; i<m ; i++){
        arr[i]=NULL;
        for(int j=0 ; j<n ; j++){
            if(mat[i][j] != 0){
                t = new Node;
                t->row = i;
                t->col = j;
                t->val = mat[i][j];
                t->next=NULL;
                if(arr[i] == NULL){
                    arr[i] = t;
                    p=t;
                } else {
                    p->next = t;
                    p=t;
                }
            }
        }
    }
}

void Display(Node* arr[5], int m, int n){
    Node *p=NULL;
    for(int i=0 ; i<m ; i++){
        p=arr[i];
        for(int j=0 ; j<n ; j++){
            if(p!=NULL && i == p->row && j == p->col)
            {
                cout << p->val << " ";
                p=p->next;
            }
            else
                cout << "0" << " ";
        }
        cout << endl;
    }
}

int main(){

    int mat[5][6] = {{0,0,0,0,8,0},
                     {0,0,0,7,0,0},
                     {5,0,0,0,9,0},
                     {0,0,0,0,0,3},
                     {6,0,0,4,0,0}};
    Node* arr[5]={0};

    Create(arr,mat,5,6);
    Display(arr, 5,6);
}
