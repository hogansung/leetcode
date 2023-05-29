from typing import List

INF = int(1e7)


class Solution:
    def findCheapestPrice(
        self, n: int, flights: List[List[int]], src: int, dst: int, k: int
    ) -> int:
        states = [[INF for _ in range(k + 2)] for _ in range(n)]
        states[src][0] = 0
        for _k in range(k + 1):
            for u, v, p in flights:
                states[v][_k + 1] = min(states[v][_k + 1], states[u][_k] + p)
        minv = INF
        for _k in range(k + 2):
            minv = min(minv, states[dst][_k])
        return minv if minv != INF else -1
