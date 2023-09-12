class Solution:
    def dfs(self, idx: int) -> int:
        if idx == self.n:
            return 1
        res = 0
        for val in range(1, self.n + 1):
            if (val % (idx + 1) == 0 or (idx + 1) % val == 0) and not self.visited[val]:
                self.visited[val] = True
                res += self.dfs(idx + 1)
                self.visited[val] = False
        return res

    def countArrangement(self, n: int) -> int:
        self.n = n
        self.visited = [False for _ in range(n + 1)]
        return self.dfs(0)
