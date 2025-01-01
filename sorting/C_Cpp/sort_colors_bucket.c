
void sortColors(int* nums, int numsSize) {
    int counts[3] = {0, 0, 0};
    for (int i = 0; i < numsSize; i++) {
        counts[nums[i]]++;
    }
    int c = 0;
    for (int i=0; i<3; i++) {
        for (int j=0; j < counts[i]; j++) {
            nums[c] = i;
            c++;
        }
    }
}
