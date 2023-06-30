#include <iostream>

using namespace std;

void Insert(int A[], int n){
    int i=n,j,temp;
    temp = A[n];
    while(i>1 && temp>A[i/2]){
        A[i] = A[i/2];
        i/=2;
    }
    A[i] = temp;
}

int Delete(int A[], int n){
    int i,j,temp,val;
    val = A[1];
    A[1] = A[n];
    i=1;
    j = 2*i;
    while(j<=n-1){
        if(A[j+1] > A[j])
            j = j+1;

        if(A[i] < A[j]){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = j*2;
        }
        else
            break;
    }
    A[n] = val;
    return val;
}


int main()
{
    int H[] = {0,10,20,30,25,5,40,35};
    // Insert
    for(int i=2 ; i<=7 ; i++)
        Insert(H,i);

//    // Delete
//    cout << Delete(H,7) << endl;

    // Heap Sort
    for(int i=7 ; i>1 ; i--)
        Delete(H,i);

    // Display
    for(int i=1 ; i<=7 ; i++)
        cout << H[i] << " ";
}
