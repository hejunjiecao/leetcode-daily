#include <stdio.h>
int search_left_border(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int left_border = -1;
    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (nums[middle] < target)
            left = middle + 1;
        if (nums[middle] > target)
            right = middle - 1;
        if (nums[middle] == target)
        {
            left_border = middle;
            right = middle - 1;
        }
    }
    return left_border;
}

int search_right_border(int* nums, int numsSize, int target)
{
    int left  = 0;
    int right = numsSize - 1;
    int right_border = -1;
    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (nums[middle] < target)
            left = middle + 1;
        if (nums[middle] > target)
            right = middle - 1;
        if (nums[middle] == target)
        {
            right_border = middle;
            left = middle + 1;
        }
    }
    return right_border;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int left_border = search_left_border(nums, numsSize, target);
    int right_border = search_right_border(nums, numsSize, target);
    int* result = malloc(2 * sizeof(int));
    result[0] = left_border;
    result[1] = right_border;
    *returnSize = 2;
    return result;
}
