import math
from typing import Tuple, List


class Solution:
    def dfs(self, u: int, p: int) -> Tuple[int, int]:
        node_sum = 0
        fuel_sum = 0
        for v in self.edges[u]:
            if v == p:
                continue
            s_node_sum, s_fuel_sum = self.dfs(v, u)
            node_sum += s_node_sum
            fuel_sum += s_fuel_sum
        node_sum += 1
        fuel_sum += math.ceil(node_sum / self.seats)
        return node_sum, fuel_sum

    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        n = max(1, len(set([node for nodes in roads for node in nodes])))
        self.edges = [[] for _ in range(n)]
        for u, v in roads:
            self.edges[u].append(v)
            self.edges[v].append(u)
        self.seats = seats
        fuel_sum = 0
        for v in self.edges[0]:
            _, s_fuel_sum = self.dfs(v, 0)
            fuel_sum += s_fuel_sum
        return fuel_sum
