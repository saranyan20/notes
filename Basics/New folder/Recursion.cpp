#include <iostream>
using namespace std;

int fun(int n){
	if(n>0){	
		fun(n-1)*2;
		cout << n << endl;
	}
	return 1;
}
int main(){
	fun(5);
	return 0;
}
