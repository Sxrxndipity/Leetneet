#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {

    int n = numsSize;
    int* arr = malloc(2*n*sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = nums[i];
        arr[i+n] = nums[i];
    }
    *returnSize = 2*n;
    return arr;
}
