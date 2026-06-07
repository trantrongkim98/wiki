class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # 1. sort array 
        intervals.sort(key=lambda x: x[0])
        result = []
        merging = intervals[0]
        i = 0
        while i<len(intervals)-1:
            if merging[1] >= intervals[i+1][0]:
                merging = [merging[0],max(merging[1],intervals[i+1][1])]
            else:
                result.append(merging)
                merging = intervals[i+1]
            i+=1
        if len(result) ==0:
            return [merging]
        if merging[1] >= result[len(result)-1][1]:
            result.append(merging)
        return result
                
