int removeDuplicates(int* nums, int numsSize) {
    int n = numsSize;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                // shift left from j to n-1
                for (int k = j; k < n - 1; k++) {
                    nums[k] = nums[k + 1];
                }
                n--;    // one element removed
                j--;    // stay at same j to re-check the new element moved here
            }
        }
    }

    // optional: print resulting array (space separated)
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return n;
}
