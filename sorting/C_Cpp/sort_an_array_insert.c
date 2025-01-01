#include <stdlib.h>

int* sortArray(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    int *res = (int*)malloc(sizeof(int)*n);


    for (int i=0; i<n; i++) {
        res[i] = nums[i];
    }

    for (int i=1; i<n; i++) {
        int j = i-1;
        while (j>=0 && res[j+1] < res[j]) {
            int temp = res[j+1];
            res[j+1] = res[j];
            res[j] = temp;
            j-=1;
        }
    }

    *returnSize = n;
    return res;
}
