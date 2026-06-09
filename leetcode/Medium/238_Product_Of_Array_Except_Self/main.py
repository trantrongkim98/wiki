from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left = 1
        numsCount = len(nums)
        right = numsCount-2
        arrLeft = [1 for i in range(numsCount)]
        arrRight = [1 for i in range(numsCount)]
        iAns = 0
        answers = [1 for i in range(numsCount)]
        while left < numsCount:
            arrLeft[left] = arrLeft[left-1]*nums[left-1]
            arrRight[right] = arrRight[right+1] * nums[right+1] 
            right-=1
            left+=1
        while iAns < numsCount:
            answers[iAns] = arrLeft[iAns]*arrRight[iAns]
            iAns+=1
        return answers
        
    
s = Solution()
nums = [1,2,3,4]
print(s.productExceptSelf(nums))