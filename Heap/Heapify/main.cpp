#include <iostream>

using namespace std;

void Heapify(int A[], int n){
    int i,j;
    i = A[n];
    j = 2*i;

    if(j+1 > j)
        j = j+1;

    if(A[i] < A[j]){

    }
}

int main()
{
    int H[] = {0,5,10,30,20,35,40,15};
    Heapify(H,7);
    return 0;
}
