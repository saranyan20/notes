#include<iostream>
using namespace std;

int main(){
	int A[] = {8,7,6,4,6,5,6,8,2,7}, count = 1;
	for(int i=0 ; i<10 ; i++){
		
		for(int j=i+1 ; j<10 ; j++){
			if(A[i] == A[j] && A[j] != -1){
				count++;
				A[j] = -1;
			}
		}
		if(count >1)
			cout << A[i] << " " << count << endl;
		count = 1;
		
	}
}
