#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

typedef int (*pfSort)(int *,int);

int main(int argc,char** argv)
{
    pfSort pSort = NULL;
    int *pNumArray = NULL;
    int number;
    char method;

    if(3 != argc) {
        return 0;
    }

    number = atoi(argv[2]);
    if(number > 999999) {
        return 0;
    }

    method = atoi(argv[1]);
    switch(method) {
        case 1:
            pSort = insertionSort;
            break;
        case 2:
            pSort = mergeSort;
            break;
        case 3:
            pSort = heapSort;
            break;
        default:
            printf("unsupported sorting method!\n");
            return 0;
    }

    pNumArray = malloc(sizeof(int)*number);
    if(NULL == pNumArray) {
        return 0;
    }

    for(int i=0;i<number;i++) {
        pNumArray[i] = random();
    }

    if(pSort(pNumArray,number) < 0) {
        printf("sort error!\n");
        free(pNumArray);
        return 0;
    }

    for(int i=0;i<number;i++) {
        printf("%d\n",pNumArray[i]);
    }

    free(pNumArray);
    return 0;
}
