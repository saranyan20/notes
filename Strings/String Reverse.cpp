#include<iostream>
using namespace std;

int main(){
	char str[100];
	int i;
	cin >> str;
	for(i=0 ; str[i]!='\0' ; i++){
		
	}
	i-=1;
	for(int j=0 ; j<i ; j++,i--){
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	cout << str;	
}
