int removeElement(int* nums, int numsSize, int val) {


    int k = numsSize;
    int n  = numsSize;
    int *l = nums +n -1;
    for(int i=0; i < n; i++){
        if (*l == val) {
            l-=1;
        }
        if (nums[i] == val){
            nums[i] = *l;
            k-=1;
            l-=1;
        }
    }
    return k;



}
