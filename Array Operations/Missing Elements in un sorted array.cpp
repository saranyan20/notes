#include<iostream>
using namespace std;

int main(){
	int arr[] = {3,7,4,9,12,6,20,11,2,10};
	int max = arr[0];
	int min = arr[0];
	for(int i=0 ; i<9 ; i++){
		if(max < arr[i]){
			max = arr[i];
		}
		if(min > arr[i]){
			min = arr[i];
		}
	}
	int h[max+1]={0};
	for(int i=0 ; i<10 ; i++){
		h[arr[i]] = 1;
	}
	for(int i=min ; i<max+1 ; i++){
		if(h[i] == 0){
			cout << i << endl;
		}
	}
}
