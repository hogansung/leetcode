from typing import List


class Solution:
    def dfs(self, idx: int) -> bool:
        if idx == 2 * self.n - 1:
            self.res = self.arr[:]
            return True
        if self.arr[idx] is not None:
            return self.dfs(idx + 1)
        for val in range(2, min(self.n + 1, 2 * self.n - 1 - idx))[::-1]:
            if self.visited[val] or self.arr[idx + val] is not None:
                continue
            self.arr[idx] = val
            self.visited[val] = True
            self.arr[idx + val] = val
            suc = self.dfs(idx + 1)
            self.arr[idx] = None
            self.visited[val] = False
            self.arr[idx + val] = None
            if suc:
                return suc
        if not self.visited[1]:
            self.arr[idx] = 1
            self.visited[1] = True
            suc = self.dfs(idx + 1)
            self.arr[idx] = None
            self.visited[1] = False
            return suc
        return False

    def constructDistancedSequence(self, n: int) -> List[int]:
        self.n = n
        self.visited = [False for _ in range(n + 1)]
        self.arr = [None for _ in range(2 * n - 1)]
        self.res = None
        assert self.dfs(0) == True
        return self.res
