from typing import List


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        sorted_points = sorted(points, key=lambda point: point[1])
        cnt = 0
        idx = 0
        while idx < len(sorted_points):
            cnt += 1
            curr_boundary = sorted_points[idx][1]
            while idx < len(sorted_points) and sorted_points[idx][0] <= curr_boundary:
                idx += 1
        return cnt
