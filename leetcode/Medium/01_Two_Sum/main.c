#include <stdlib.h>
#include "stdio.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//     int result[] = {nums[0],nums[1]};
//     returnSize = 2;
//     return &result;
// }

int main(int argc, char const *argv[])
{
    int *nums = (int *)malloc(6*sizeof(int));
    
    for(int i = 0; i < 6; i++){
        nums[i] = i+1;
    }
    // int* returnSize = malloc(sizeof(int));
    // twoSum(nums,6,6,returnSize);
    // nums++;
    // nums++;
    // printf("%d\n", *nums);
    for(int i = 0; i < 9; i++){
     printf("%d\n", *nums);
        nums++;
    }
    // while (nums!=NULL) {
    //     printf("%d\n", *nums);
    //     nums++;
    // }

    return 0;
}
