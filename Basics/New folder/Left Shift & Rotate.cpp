#include<iostream>
using namespace std;

struct array {
	int a[10];
	int length ; 
	int size;
};

void leftshift(struct array *arr){
	if(arr->length < arr->size){
		for(int i=1 ; i<arr->length ; i++){
			arr->a[i-1] = arr->a[i];
		}
		arr->a[arr->length-1] = 0;
	}
}

void rightshift(struct array *arr){
	if(arr->length < arr->size){
		for(int i=arr->length-1 ; i>=0 ; i--){
			arr->a[i] = arr->a[i-1];
		}
	}
	arr->a[0] = 0;
}

void leftrotate(struct array *arr){
	if(arr->length < arr->size){
		int x = arr->a[0];
		for(int i=1 ; i<arr->length ; i++){
			arr->a[i-1] = arr->a[i];
		}
		arr->a[arr->length-1] = x;
	}
}


void rightrotate(struct array *arr){
	if(arr->length < arr->size){
		int x = arr->a[arr->length-1];
		for(int i=arr->length-1 ; i>=0 ; i--){
			arr->a[i] = arr->a[i-1];
		}
		arr->a[0] = x;
	}
}

void display(struct array arr){
	for(int i=0 ; i<arr.length ; i++){
		cout << arr.a[i];
	}
}

int main(){
	struct array arr = { {2,3,4,5,6} ,5 ,10};
	int  i =0;
	while(i<5){
	
		display(arr);
		cout << endl ;
		rightrotate(&arr);
		display(arr);
		cout << endl << endl;
		i++;
}
	
}
