#include<iostream>
using namespace std;

int main(){
	int n[] = {6,7,8,9,11,14,15,16,17,19};
	int diff = n[0]-0;
//	Single missing element
//	for(int i=0 ; i<11 ; i++){
//		if(n[i] - i == diff){
//			diff = n[i] - i;
//		} else {
//			cout << n[i]-1;
//			diff++;
//		}
//	
//	}
//	More than one missing elements
	for(int i=0 ; i<10 ; i++){
		if(n[i] - i != diff){
			while(diff < n[i]-i){
				cout << i+diff << endl;
				diff++;
			}
		}
	}
}
