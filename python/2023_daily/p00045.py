import queue
from typing import List

INF = int(1e4)


class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        dis = [INF for _ in range(n)]
        q = queue.Queue()
        q.put(0)
        dis[0] = 0
        while q.qsize():
            idx = q.get()
            for jdx in range(1, min(nums[idx], n - 1 - idx) + 1):
                if dis[idx + jdx] == INF:
                    dis[idx + jdx] = dis[idx] + 1
                    q.put(idx + jdx)
        return dis[n - 1]
