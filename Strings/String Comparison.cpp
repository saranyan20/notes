#include<iostream>
using namespace std;

int main(){
	char str1[100], str2[100];
	int i;
	cin >> str1;
	cin >> str2;
	
	for(int i=0 ; str1[i]!='\0',str2[i]!='\0' ; i++){
		if(str1[i] != str2[i])	
		{
			if(str1[i] < str2[i]){
				cout << str1 << endl << str2;
				return 0;
		}
		
			else {
			
				cout << str2 << endl << str1;
				return 0;
			}
		}
	}
//	cout << str;	
}
