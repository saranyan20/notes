#include <iostream>
using namespace std;

struct Array{
	int *a;
	int size;
	int length;
};


void search(struct Array arr){
	int val, i;
	cout << "------Search------" << endl;
	cout << "Enter the value";
	cin >> val;
	for(i=0 ; i<arr.length ; i++){
		if(arr[i] == val){
			break;
		}
	}
	cout << "Element found in index " << i;
}

void del(struct Array *arr){
	cout << endl << "------Delete------" << endl;
	int index;
	cout << "Enter the value: ";
	cin >> index;
	if(index >=0 && index < arr->length){
		int x = arr->a[index];
		for(int i=index ; i<arr->length-1 ; i++){
			arr->a[i] = arr->a[i+1]; 
		}
		cout << endl << "Element " << x << " is deleted !! " << endl;
		arr->length--;
	}

}

void insert(struct Array *arr){
	cout << endl << "------Insert------" << endl;
	int val ,index;
	cout << "Enter the value: ";
	cin >> val;
	cout << endl << "Enter the index: ";
	cin >> index;
	if(index>=0 && index <arr->length){
		for(int i=arr->length ; i>index ; i--){
			arr->a[i] = arr->a[i-1];
		}
		arr->a[index] = val;
		arr->length++;
	}
	cout << endl << "Inserted successfully!!" << endl;
}


void append(struct Array *arr){
	int val;
	cout << endl << "------Append------" << endl;
	cout << "Enter the Value: ";
	cin >> val;
	if(arr->length < arr->size){
		arr->a[arr->length++] = val;
	}
	cout << endl << "An element is appended" << endl;
}

void create(struct Array *arr){
	cout << endl << "------Create------" << endl;
	cout << "Enter the array size: ";
	cin >> arr->size;
	arr->a = new int[arr->size];
	
	cout << "Enter the array lenght: ";
	cin >> arr->length; 
	
	for(int i=0 ; i<arr->length ; i++){
		cin >> arr->a[i];
	} 
	
	cout << endl << "Array is created !!" << endl;
}

void display (struct Array arr){
	cout << endl << "	--Display--" << endl;
	cout << "Array elements are:" << endl;
	for(int i=0 ; i<arr.length ; i++){
		cout << arr.a[i] << " ";
	}
	
	cout << endl << "Array Displayed !!" << endl;
}

int main(int argc, char** argv) {
	struct Array arr;
	int opt;
	
	while(true){
		cout << "Array Manipulations" << endl;
		cout << "1.Create" << endl;
		cout << "2.Display" << endl;
		cout << "3.Append" << endl;
		cout << "4.Insert" << endl;
		cout << "5.Delete" << endl;
		cout << "5.Search" << endl;

		cout << "10.Exit" << endl;


		cout << "Enter an option: ";
		cin >> opt;
		
		switch(opt){
			case 1: create(&arr);
					break;
			case 2: display(arr);
					break;
			case 3: append(&arr);
					break;
			case 4: insert(&arr);
					break;
			case 5: del(&arr);
					break;
			case 5: search(arr);
					break;
			case 10: return 0;
					
		}	
	}
}
