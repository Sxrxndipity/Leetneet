int quickselect(int* arr, int s, int e, int k) {

    if(e-s+1 <= 1) {
        return arr[s];
    }

    int left = s;
    int pivot = arr[e];
    // partitioning
    for (int i=s; i<e; i++) {
        int tmp;
        if(arr[i] >= pivot) {
            tmp = arr[i];
            arr[i] = arr[left];
            arr[left] = tmp;
            left++;
        }
    }
    arr[e] = arr[left];
    arr[left] = pivot;
    if (left==k) {
        return arr[left];
    }
    else if(left>k) {
        return quickselect(arr, s, left-1, k);
    }
    else {
        return quickselect(arr, left+1, e, k);
    }
}


int findKthLargest(int* nums, int numsSize, int k) {
    // k-1 because the arr is using 0 based indexing whilst the value k is never 0 k=1 refers to the largest int
    return quickselect(nums, 0, numsSize-1, k-1);
}
