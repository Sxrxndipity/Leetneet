#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int* arr = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int x = 0;
    int y = n;
    int i = 0;
    while (i < numsSize) {
        if (i % 2 == 0 && x < n) {
            arr[i] = nums[x];
            x++;
            i++;
        }
        else if (i % 2 == 1 && y < numsSize) {
            arr[i] = nums[y];
            y++;
            i++;
        }
    }
    return arr;
}
