class Solution:
    def dfs(self, idx: int, b_inc: bool) -> bool:
        if b_inc:
            candidates = range(self.arr[idx - 1] + 1, 10)
        else:
            candidates = range(1, self.arr[idx - 1])
        for val in candidates:
            if self.visited[val]:
                continue
            if idx == self.n - 1:
                self.arr[idx] = val
                self.res = self.arr[:]
                return True
            self.arr[idx] = val
            self.visited[val] = True
            suc = self.dfs(idx + 1, self.pattern[idx] == "I")
            self.visited[val] = False
            if suc:
                return True
        return False

    def smallestNumber(self, pattern: str) -> str:
        self.pattern = pattern
        self.n = len(pattern) + 1
        self.visited = [False for _ in range(10 + 1)]
        self.arr = [None for _ in range(self.n)]
        self.res = None
        for val in range(1, 10):
            self.visited[val] = True
            self.arr[0] = val
            if self.dfs(1, pattern[0] == "I"):
                return "".join(map(str, self.res))
            else:
                self.visited[val] = False
        assert False
