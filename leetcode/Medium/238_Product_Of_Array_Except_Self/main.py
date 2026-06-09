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
        
# Sử dụng 2 con trỏ để giải quyết bài toán này
# Chia mảng thành 2 phần trái và phải
# Sau đó tính tích bên phải và bên trái
# Tích bên trái sẽ bằng tích của các phần tử đằng trước nó 
# suy ra ta có index bắt đầu từ 1 và công thức arrLeft[left-1]*nums[left-1]
# Tích bên phải sẽ bằng tích của các phần tử đằng sau nó
# suy ra ta có index bắt đầu từ lengh -2 và công thức arrRight[right+1] * nums[right+1] 
# Cuối cùng nhân 2 mảng trái phải lại với nhau sẽ được kết quả
    
s = Solution()
nums = [1,2,3,4]
print(s.productExceptSelf(nums))