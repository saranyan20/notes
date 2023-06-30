#include<iostream>
using namespace std;


struct Array{
	int a[10];
	int length;
	int size;
};

Array* merge(struct Array *arr1 , struct Array *arr2){
	
	struct Array *arr3 = new Array[1];
	int i,j,k;
	i=j=k=0;
	
	while(i < arr1->length && j < arr2->length){
		if(arr1->a[i] < arr2->a[j])
			arr3->a[k++] = arr1->a[i++];
		else 
			arr3->a[k++] = arr2->a[j++];
	}
	
	for( ; i<arr1->length ; i++)
		arr3->a[k++] = arr1->a[i];
	
	for( ; j<arr2->length ; j++)
		arr3->a[k++] = arr2->a[j];
	
	arr3->length = arr2->length + arr1->length;
	arr3->size = 10;
	
	return arr3;	
}

void display(struct Array arr3){
	for(int i=0 ; i<arr3.length ; i++){
		cout << arr3.a[i] << " ";
	}
}

int main(){
	struct Array arr1{{10,25,62,78,99}, 5, 10};
	struct Array arr2{{12,27,69,71,92}, 5, 10};
	struct Array *arr3;
	arr3 = merge(&arr1,&arr2);
	display(*arr3);		
}
