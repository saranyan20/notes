#include<iostream>
using namespace std;

int fun(int arr[], int n){
	int i,j;
	int flag = 0;
	int temp[n];
	
	for(i=0,j=0 ; i<n ; j++){
		if(arr[i]%2 == 0 && arr[i+1]%2 == 0){
			temp[j] = arr[i];
			i+=2;
			flag++;
		}
		else if(arr[i]%2 == 1 && arr[i+1]%2 == 1){
			temp[j] = arr[i];
			i+=2;
			flag++;
		}
		else{
			temp[j] = arr[i];
			i++;
		}
			
	}
	if(flag == 0){
		for(int i=0 ; i<j; i++){
			cout << temp[i] << " ";
		}
		return 0;
	}
	return fun(temp,j);
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0 ; i<n ; i++){
		cin >> arr[i];
	}	fun(arr,n);

}
