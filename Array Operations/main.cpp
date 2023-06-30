#include <iostream>
using namespace std;

class Array{
	
	private:
		int *A;
		int size;
		int length;
	
	public:
		Array(){
			size = 10;
			length = 0;
			A = new int[size];
		}
		Array(int sz){
			size = sz;
			length = 0;
			A = new int[size];
		}
		~Array(){
			delete []A;
		}
		
		void Display();
		void Insert(int val, int index);
		void Delete(int index);
		int LinearSearch(int val);
		int BinarySearch(int val);
		int Get(int val);
		void Set(int val, int index);
		int Max();
		int Min();
		void Reverse();
		void Shift();
		void Sum();
		void Average();
		void Merge();
		void Union();
		void Intersection();
		void Difference();
};

void Array::Display(){
	for(int i=0 ; i<length ; i++){
		cout << A[i] << " ";
	}
}

void Array::Insert(int val, int index){
	if(index >= 0 && index <= length){
		for(int i=length-1 ; i>=index ; i--)
			A[i+1] = A[i];
		A[index] = val;
		length++;
	}
}

void Array::Delete(int index){
	if(index >= 0 && index < length){
		int x = A[index];
		for(int i=index ; i<length ; i++){
			A[i] = A[i+1];
		}
		length--;
	}
	cout << endl;
}

int Array::LinearSearch(int val){
	for(int i=0 ; i<length ; i++){
		if(A[i] == val){
			return i;
		}
	}
	return 0;
}

int Array::Get(int val){
	for(int i=0 ; i<length ; i++){
		if(A[i] == val){
			return i;
		}
	}
	return 0;
}

void Array::Set(int val, int index){
	if(index>=0 && index<length){
		A[index] = val;
	}
}

int Array::Max(){
	int max = A[0];
	for(int i=0 ; i<length ; i++){
		if(max < A[i]){
			max = A[i];
		}
	}
	return max;
}
int Array::Min(){
	int min = A[0];
	for(int i=0 ; i<length ; i++){
		if(min > A[i]){
			min = A[i];
		}
	}
	return min;
}

int main(int argc, char** argv) {
	
	Array a(10);
	a.Insert(11,0);
	a.Insert(22,1);
	a.Insert(33,2);
	a.Insert(44,3);
	a.Insert(55,4);
	a.Insert(66,5);
//	a.Display();

//	a.Delete(4);
//	a.Display();

//	cout <<	a.LinearSearch(100);

//	cout << a.Get(55);

//	a.set(56,4);
//	a.Display();

	cout << a.Max();
	cout << a.Min();

	
	return 0;
}
