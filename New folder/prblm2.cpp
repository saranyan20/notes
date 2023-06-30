#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	cout << "Array Elemets are:";
	for(int i=0 ; i<n ; i++){
		cin >> arr[i];
	}
	
	for(int i=0 ; i<n ; i++){
		int count = 0;
		for(int j=n-1 ; j>=0 ; j--){
			count++;
			if(count == arr[i]){
				cout << arr[j];
				break;
			}
		}
	}
	return 0;
}
