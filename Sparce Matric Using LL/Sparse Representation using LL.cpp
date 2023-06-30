#include <iostream>
using namespace std;

struct Node{
    int row;
    int col;
    int val;
    struct Node *next;
}*head = NULL;


void Create(int mat[5][6], int m, int n){
    Node *p, *t;
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(mat[i][j] != 0){
                if(head == NULL){
                    head = new Node;
                    head->next = NULL;
                    head->row = i;
                    head->col = j;
                    head->val = mat[i][j];
                    p = head;
                } else {
                    t = new Node;
                    t->next = NULL;
                    t->row = i;
                    t->col = j;
                    t->val = mat[i][j];
                    p->next = t;
                    p = t;
                }
            }
        }
    }
}

void Display(struct Node *p, int m, int n){
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(p!=NULL && i == p->row && j == p->col){
                cout << p->val << " ";
                p = p->next;
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
                     {6,0,0,4,0,0}
                    };
    Create(mat,5,6);
    Display(head,5,6);
}
