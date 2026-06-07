#include "stdio.h"

int jump(int *nums, int numsSize)
{
    int jumps = 0, maxJumps = 0, curIndex = numsSize, endIndex = nums[0], startIndex = 0;
    
    if(numsSize == 1) return numsSize;
    if(*nums == 0)  return 0;
  

    while (curIndex-->=0)
    {
        
    }

    return jumps;
}


int main()
{
    int nums[] = {0,1,2,3,4,5};
    int size = sizeof(nums) / sizeof(nums[0]);
    int jumps = jump(nums, size);
    printf("jumps = %d\n", jumps);
    return 0;
}