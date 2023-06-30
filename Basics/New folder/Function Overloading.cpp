#include<iostream>
using namespace std;

int max(int a, int b){
	return a+b;
}
int max(int a, int b, int c){
	return a+b+c;
}
float max(float a, float b){
	return a+b;
}

int main()
{
	cout<<max(5, 6, 7)<<endl;
	cout<<max(5, 6)<<endl;
	cout<<max(5.5f, 6.6f)<<endl;
	return 0;
}
