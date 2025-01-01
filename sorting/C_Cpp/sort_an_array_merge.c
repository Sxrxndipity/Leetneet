#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r); //left portion and right portion
void merge_sorted_arrays(int a[], int l, int m, int r); // middle

int* sortArray(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    int* res = (int*)malloc(sizeof(int)*n);

    for (int i=0; i<n; i++) {
        res[i] = nums[i];
    }
    *returnSize = n;
    merge_sort(res, n);

    return res;
}

void merge_sort(int a[], int length) {
    merge_sort_recursion(a, 0, length - 1);
}

void merge_sort_recursion(int a[], int l, int r) {

    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort_recursion(a, l ,m);
        merge_sort_recursion(a, m + 1, r);

        merge_sorted_arrays(a, l, m, r);
    }
}

void merge_sorted_arrays(int a[], int l, int m, int r) {

    int left_length = m - l + 1;
    int right_length = r - m;

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;

    for (i = 0; i < left_length; i++) {
        temp_left[i] = a[l+i];
    }

    for (i = 0; i < right_length; i++) {
        temp_right[i] = a[m+1+i];
    }

    for (i=0, j=0, k=l; k <= r; k++) {
        if ((i < left_length) && (j >= right_length) || temp_left[i] <= temp_right[j]) {
            a[k] = temp_left[i];
            i++;
        } else {
            a[k] = temp_right[j];
            j++;
        }
    }
}

