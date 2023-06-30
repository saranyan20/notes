#include<iostream>
using namespace std;

int main(){
	int A[] = {3,6,8,8,10,15,15,15,20,20};
	int count = 0;
	
//	---------------------Unsorted Array-------------------------------------------
//	for(int i=0 ; i<10 ; i++){
//		if(A[i] == A[i+1]){
//			if(count <=1){
//				cout << A[i] << endl;
//				count++;
//			}
//		 else 
//			count =0;
//		}
//	}

//	------------------------Finding count of duplicates-----------------------------
//	for(int i=0 ; i<10 ; i++){
//		if(A[i] == A[i+1]){
//			int j = i+1;
//			while(A[j] == A[i]) j++;
//			cout << A[i] << " " << j-i << endl;
//			i=j;
//		}
//	}

//	-------------------------Finding Duplicates element using hash tabel-------------
	int max=A[0];
	for(int i=0 ; i<10 ; i++){
		if(max < A[i]){
			max = A[i];
		}
	}
	int H[max] = {0	};
	for(int i=0 ; i<10 ; i++){
		H[A[i]] += 1;
	}
	for(int i=0 ; i<max ; i++){
		if(H[i]>1){
			cout << i << " " << H[i] << endl;
		}
	}
}
