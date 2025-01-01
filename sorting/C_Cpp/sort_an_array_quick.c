int* quicksort(int* arr, int s, int e);


int* sortArray(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
   *returnSize = n;
    quicksort(nums, 0, n-1);
    return nums;
}

int* quicksort(int* arr, int s, int e){
    int left = s;
    int pivot = arr[e];

    if ((e-s+1) <= 1){
        return arr;
    }

    for (int i=s; i<e; i++) {
        int tmp;
        if (arr[i] < pivot) {
            tmp = arr[left];
            arr[left] = arr[i];
            arr[i] = tmp;
            left++;
        }
    }

    arr[e] = arr[left];
    arr[left] = pivot;
    quicksort(arr, s, left-1);
    quicksort(arr, left+1, e);
    return arr;
}
