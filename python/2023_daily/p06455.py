class Solution:
    def minimumCost(self, s: str) -> int:
        n = len(s)
        # left to right
        z_idx = None
        o_idx = None
        lz_cost = [0 for _ in range(n + 1)]
        lo_cost = [0 for _ in range(n + 1)]
        for idx in range(n + 1):
            lz_cost[idx] = 0 if o_idx is None else lo_cost[o_idx] + o_idx + 1
            lo_cost[idx] = 0 if z_idx is None else lz_cost[z_idx] + z_idx + 1
            if idx < n:
                if s[idx] == "0":
                    z_idx = idx
                else:
                    o_idx = idx
        # right to left
        z_idx = None
        o_idx = None
        rz_cost = [0 for _ in range(n)]
        ro_cost = [0 for _ in range(n)]
        for idx in range(n)[::-1]:
            rz_cost[idx] = 0 if o_idx is None else ro_cost[o_idx] + n - o_idx
            ro_cost[idx] = 0 if z_idx is None else rz_cost[z_idx] + n - z_idx
            if s[idx] == "0":
                z_idx = idx
            else:
                o_idx = idx
        minv = int(1e10)
        for idx in range(n):
            minv = min(minv, lz_cost[idx + 1] + rz_cost[idx])
            minv = min(minv, lo_cost[idx + 1] + ro_cost[idx])
        return minv
