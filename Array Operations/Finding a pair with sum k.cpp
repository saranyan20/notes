#include <iostream>
using namespace std;

int main(){
    int A[] = {6,3,8,10,16,7,5,2,9,4,0};
    for(int i=0 ; i<11 ; i++){
        for(int j=i+1 ; j<11 ; j++){
            if(A[i] + A[j] == 10){
                cout << A[i] << " " << A[j] << endl;
            }
        }
    }
}
