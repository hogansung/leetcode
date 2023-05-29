import queue
from typing import List

INF = int(1e4)


class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        q = queue.Queue()
        dis = [[INF for _ in range(m)] for _ in range(n)]
        for idx in range(n):
            for jdx in range(m):
                if grid[idx][jdx] == 1:
                    q.put((idx, jdx))
                    dis[idx][jdx] = 0
        if q.qsize() == 0 or q.qsize() == n * m:
            return -1
        directions = [(+1, 0), (-1, 0), (0, +1), (0, -1)]
        maxv = 0
        while q.qsize():
            r, c = q.get()
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if nr < 0 or nr == n or nc < 0 or nc == m:
                    continue
                if dis[nr][nc] == INF:
                    dis[nr][nc] = dis[r][c] + 1
                    q.put((nr, nc))
                    maxv = max(maxv, dis[nr][nc])
        return maxv
