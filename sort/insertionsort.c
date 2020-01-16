#include <stdio.h>

int insertionSort(int *nums,int size) {
    int temp;

    if(NULL == nums) {
        return -1;
    }

    if(1 == size) {
        return 0;
    }

    if(size <= 0) {
        return -1;
    }

    for(int i=1;i<size;i++) {
        int j;
        temp = nums[i];
        j = i - 1;
        while(j >= 0 && nums[j] > temp) {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = temp;
    }

    return 0;
}