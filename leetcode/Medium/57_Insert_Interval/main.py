from typing import List


class Solution:

    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        if len(intervals) == 0:
            return [newInterval]
        i = 0
        result = []
        merging = newInterval
        isMerging = False
        # 1. merging inside interval
        # 2. interval inside merging
        # 3. minMerging inside interval
        # 4. maxMerging inside interval
        lenth = len(intervals)
        while i < lenth:
            interval = intervals[i]
            i += 1
            print(interval)
            if interval[0] > merging[1]:
                if isMerging == False:
                    isMerging = True
                    result.append(merging)
                result.append(interval)
            elif interval[1] < merging[0]:
                result.append(interval)
                if lenth == 1 and isMerging == False:
                    isMerging = True
                    result.append(merging)
            else:
                mMin = min(interval[0], merging[0])
                mMax = max(interval[1], merging[1])
                merging = [mMin, mMax]
                if lenth == 1 and isMerging == False:
                    isMerging = True
                    result.append(merging)
        if len(result) == 0 or isMerging == False:
            result.append(merging)
        return result


s = Solution()
intervals = [[2, 3], [5, 7]]
newInterval = [0, 6]

print(s.insert(intervals, newInterval))
