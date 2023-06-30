#include<iostream>
using namespace std;

int main(){
	int *p = new int[3];
	for(int i=0 ; i<3 ; i++){
		cin>>p[i];
	}
	for(int i=0 ; i<5 ; i++ ){
		cout<<p[i]<<" ";
	}
	cout<<endl<<p;
	cout<<"Array size change";
//	delete []p;
	p = new int[5];
	for(int i=0 ; i<5 ; i++){
		cin>>p[i];
	}
	for(int i=0 ; i<5 ; i++){
		cout<<p[i]<<" ";
	}
	cout<<endl<<p;
}
