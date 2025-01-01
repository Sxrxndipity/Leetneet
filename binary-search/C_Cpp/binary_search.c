int search(int* nums, int numsSize, int target) {

    int n = numsSize;
    int low = 0;
    int high = n-1;

    while (low <= high) {
        int m  = (low + high) / 2;
        if (target < nums[m]){
            high = m - 1;
        }
        else if (target > nums[m]){
            low  = m + 1;
        }
        else {
            return m;
        }
    }

    return -1;
}
