
int removeDuplicates(int* nums, int numsSize) {
    int k=0;
    int n=numsSize;
    for (int i=1; i<n; i++) {

        if (nums[i-1] != nums[i]) {
            k++;
            nums[k] = nums[i];
        }
    }
    return k+1;
}
