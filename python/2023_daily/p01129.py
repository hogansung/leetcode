import queue
from typing import List

INF = int(1e4)


class Solution:
    def shortestAlternatingPaths(
        self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]
    ) -> List[int]:
        red_edges = [[] for _ in range(n)]
        for u, v in redEdges:
            red_edges[u].append(v)
        blue_edges = [[] for _ in range(n)]
        for u, v in blueEdges:
            blue_edges[u].append(v)
        q = queue.Queue()
        dis = [[INF for _ in range(2)] for _ in range(n)]
        q.put((0, 0))
        q.put((0, 1))
        dis[0][0] = dis[0][1] = 0
        while q.qsize():
            u, c = q.get()
            if c == 0:
                for v in blue_edges[u]:
                    if dis[v][1] == INF:
                        dis[v][1] = dis[u][c] + 1
                        q.put((v, 1))
            else:
                for v in red_edges[u]:
                    if dis[v][0] == INF:
                        dis[v][0] = dis[u][c] + 1
                        q.put((v, 0))
        return [-1 if min(dis[idx]) == INF else min(dis[idx]) for idx in range(n)]
