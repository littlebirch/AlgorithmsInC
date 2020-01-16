#include <stdio.h>
#include <stdlib.h>

static void mergeSortAction(int* nums,int head,int mid,int tail)
{
    int *p1,*p2;
    int j,k;
    int l1,l2;

    if(NULL == nums) {
        return;
    }

    if(head > mid || mid > tail ) {
        return;
    }

    p1 = p2 = NULL;
    l1 = mid + 1 - head;
    l2 = tail - mid;

    p1 = malloc(l1*sizeof(int));
    if(NULL == p1) {
        return;
    }

    p2 = malloc(l2*sizeof(int));
    if(NULL == p2) {
        free(p1);
        return;
    }

    for(int i=0;i<(mid+1-head);i++) {
        p1[i] = nums[head+i];
    }

    for(int i=0;i<(tail-mid);i++) {
        p2[i] = nums[mid+i+1];
    }

    j = k = 0;
    for(int i=head;i<=tail;i++) {
        if(j != l1 && k != l2) {
            if(p1[j] <= p2[k]) {
                nums[i] = p1[j];
                j++;
                continue;
            } else {
                nums[i] = p2[k];
                k++;
                continue;
            }
        }

        if(j == l1) {
            nums[i] = p2[k];
            k++;
        } else if(k == l2) {
            nums[i] = p1[j];
            j++;
        }
    }

    free(p1);
    free(p2);
    return;
}

static void merge(int* nums,int head,int tail) {
    int mid;

    if(NULL == nums) {
        return;
    }

    if(head >= tail) {
        return;
    }
    mid = (head + tail) / 2;
    merge(nums,head,mid);
    merge(nums,mid+1,tail);
    mergeSortAction(nums,head,mid,tail);
    return;
}

int mergeSort(int *nums,int size) {
    if(NULL == nums) {
        return -1;
    }

    if(1 == size) {
        return 0;
    }

    if(size <= 0) {
        return -1;
    }

    merge(nums,0,size-1);
    return 0;
}
