#include <stdio.h>

#define PARENT(I) ((I-1)/2)
#define LEFT(I) (2*I+1)
#define RIGHT(I) (2*I+2)

static void maxHeapify(int *nums,int index,int size) {
	int largest;
	int l,r;
	int temp;

	if(NULL == nums) {
		return;
	}

	if(index < 0) {
		return;
	}

	l = LEFT(index);
	r = RIGHT(index);
	largest = index;

	if(l <= size-1) {
		if(nums[index] < nums[l]) {
			largest = l;
		}
	}

	if(r <= size-1) {
		if(nums[largest] < nums[r]) {
			largest = r;
		}
	}

	if(index != largest) {
		temp = nums[index];
		nums[index] = nums[largest];
		nums[largest] = temp;
		maxHeapify(nums,largest,size);
	}

	return;
}

static void buildMaxHeap(int *nums,int size) {
	for(int i=size/2;i>=0;i--) {
		maxHeapify(nums,i,size);
	}
	return;
}


int heapSort(int *nums,int size) {
	int temp;
	int heapSize;

	if(NULL == nums) {
		return -1;
	}

	if(size < 0) {
		return -1;
	}

	buildMaxHeap(nums,size);
	heapSize = size;

	for(int i=size-1;i>=1;i--) {
		temp = nums[0];
		nums[0] = nums[i];
		nums[i] = temp;
		heapSize--;
		maxHeapify(nums,0,heapSize);
	}

	return 0;
}

#if 0
static void printArray(int *nums,int size) {
	if(NULL == nums) {
		return;
	}

	if(size < 0) {
		return;
	}

	for(int i=0;i<10;i++) {
		printf("%d\t",nums[i]);
	}
	printf("\n");

	return;
}

int main(int argc,char** argv) {
	int array[10] = {4,1,3,2,16,9,10,14,8,7};

	printArray(array,10);
	//maxHeapify(array,1,10);
	//buildMaxHeap(array,10);
	if(-1 == heapSort(array,10)) {
		printf("Error heapSort!\n");
		return 0;
	}
	printArray(array,10);
	return 0;
}
#endif