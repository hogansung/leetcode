from typing import List


class Solution:
    def subtract(self, point_a: List[int], point_b: List[int]):
        return [point_a[0] - point_b[0], point_a[1] - point_b[1]]

    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        if n == 1:
            return 1
        if n == 2:
            return 2

        max_cnt = 0
        for idx in range(n):
            for jdx in range(idx + 1, n):
                point_ij = self.subtract(points[idx], points[jdx])
                cnt = 2
                for kdx in range(jdx + 1, n):
                    point_ik = self.subtract(points[idx], points[kdx])
                    if point_ij[0] * point_ik[1] - point_ij[1] * point_ik[0] == 0:
                        cnt += 1
                max_cnt = max(max_cnt, cnt)
        return max_cnt
