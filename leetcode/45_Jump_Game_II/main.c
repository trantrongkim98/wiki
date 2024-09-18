#include "stdio.h"

int jump(int *nums, int numsSize)
{
    int jumps = 0, maxJumps = 0, curIndex = 0, endIndex = nums[0], startIndex = 0;
    if (numsSize < 3)
        return numsSize - 1;
    else if (endIndex >= numsSize - 1)
        return 1;

    while (curIndex++ < numsSize)
    {

        if (curIndex + nums[curIndex] >= maxJumps)
        {

            maxJumps = curIndex + nums[curIndex];
        }
        if (curIndex == endIndex)
        {
            jumps++;

            endIndex = maxJumps;
            if (maxJumps >= numsSize - 1)
            {
                jumps++;
                break;
            }
        }
    }

    return jumps;
}

int jump1(int *nums, int numsSize)
{
    int jumps = 0, maxJumps = 0, curIndex = 0, endIndex = nums[0], startIndex = 0;
    if (numsSize < 3)
        return numsSize - 1;
    else if (endIndex >= numsSize - 1)
        return 1;
    int *endOfArray = nums + numsSize;
    while (nums++ < endOfArray)
    {

        if (curIndex + *nums >= maxJumps)
        {

            maxJumps = curIndex + *nums;
        }
        if (curIndex == endIndex)
        {
            jumps++;

            endIndex = maxJumps;
            if (maxJumps >= numsSize - 1)
            {
                jumps++;
                break;
            }
        }
        curIndex++;
    }

    return jumps;
}

int main()
{
    int nums[] = {2,3,1,1,4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int jumps = jump(nums, size);
    printf("jumps = %d\n", jumps);
    int jumps1 = jump1(nums, size);
    printf("jumps1 = %d\n", jumps);
    return 0;
}