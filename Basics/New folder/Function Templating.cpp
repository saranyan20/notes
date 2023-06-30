#include <iostream>
using namespace std;

template <class T>
T max1(T a, T b){
	return (a>b)?a:b;
}

int main()
{
	cout << max1(5,6) << endl;
	cout << max1(5.5,6.6) << endl;
	cout << max1(5.2f,6.2f) << endl;
	return 0;
}
