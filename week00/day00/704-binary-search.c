int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while(left <= right)
    {
        int middle = left + (right - left) / 2;
        if (nums[middle] > target)
            right = middle - 1;
        if (nums[middle] < target)
            left = middle + 1;
        if (nums[middle] == target)
            return middle;
    }
    return -1;
}