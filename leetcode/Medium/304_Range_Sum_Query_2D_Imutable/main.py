from typing import List


class NumMatrix:
    def __init__(self, matrix):
        if not matrix or not matrix[0]:
            self.prefixSum = [[]]
            return

        m, n = len(matrix), len(matrix[0])
        self.prefixSum = [[0] * (n + 1) for _ in range(m + 1)]
        print(self.prefixSum)
        for i in range(m):
            for j in range(n):
                self.prefixSum[i + 1][j + 1] = (
                    self.prefixSum[i][j + 1]
                    + self.prefixSum[i + 1][j]
                    - self.prefixSum[i][j]
                    + matrix[i][j]
                )

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return (
            self.prefixSum[row2 + 1][col2 + 1]
            - self.prefixSum[row2 + 1][col1]
            - self.prefixSum[row1][col2 + 1]
            + self.prefixSum[row1][col1]
        )

# Cho ma trận A kích thước n*m, tính diện tích hình chữ nhật bất kỳ dựa vào 4 điểm f(x1,y1) và f(x2,y2) với hàm sumRegion query là O(1)
# sử dụng thuật toán 2D prefix sum để giải quyết bài toán này với thời gian build là O(n*m) và query O(1)
# 

matrix = [
    [3, 0, 1, 4, 2],
    [5, 6, 3, 2, 1],
    [1, 2, 0, 1, 5],
    [4, 1, 0, 1, 7],
    [1, 0, 3, 0, 5],
]
a = [
    [0, 0, 0, 0, 0, 0],
    [0, 3, 3, 4, 8, 10],
    [0, 8, 14, 18, 24, 27],
    [0, 9, 17, 21, 28, 36],
    [0, 13, 22, 26, 34, 49],
    [0, 14, 23, 30, 38, 58],
]
s = NumMatrix(matrix)

print(s.sumRegion(2, 1, 4, 3))
