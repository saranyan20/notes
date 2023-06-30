#include <stdio.h>
#include <stdlib.h>

struct Array {
	int *a;
	int length;
	int n;
};

void display (struct Array *arr){
	for(int i=0 ; i<arr->length ; i++){
		printf("%d ",arr->a[i]);
	}
}


int main(int argc, char *argv[]) {
	struct Array arr;
	
	printf("Enter the length : ");
	scanf("%d",&arr.length);
	
	arr.a = (int *)malloc(arr.length*sizeof(int *));
	
	printf("\nEnter the no of elements: ");
	scanf("%d",&arr.n);
	
	printf("\nEnter the elements:\n");
	
	for(int i=0 ; i<arr.n ; i++){
		scanf("%d",&arr.a[i]);
	}
	
	display(&arr);
	 
	return 0;
}
