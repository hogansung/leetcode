import queue
from typing import List

INF = int(1e5)


class Solution:
    def idx_to_coordinate(self, idx: int) -> Tuple[int, int]:
        r = idx // self.n
        c = idx % self.n
        return self.n - 1 - r, c if r % 2 == 0 else self.n - 1 - c

    def coordinate_to_idx(self, r: int, c: int) -> int:
        if (self.n - 1 - r) % 2 == 0:
            return (self.n - 1 - r) * self.n + c + 1
        else:
            return (self.n - 1 - r) * self.n + (self.n - 1 - c) + 1

    def snakesAndLadders(self, board: List[List[int]]) -> int:
        self.n = len(board)
        dis = [INF for _ in range(self.n * self.n)]
        q = queue.Queue()
        q.put(0)
        dis[0] = 0
        while q.qsize() > 0:
            idx = q.get()
            for n_idx in range(idx + 1, min(idx + 6, self.n * self.n - 1) + 1):
                nr, nc = self.idx_to_coordinate(n_idx)
                if board[nr][nc] != -1:
                    n_idx = board[nr][nc] - 1
                if dis[n_idx] == INF:
                    dis[n_idx] = dis[idx] + 1
                    q.put(n_idx)
        if dis[self.n * self.n - 1] == INF:
            return -1
        return dis[self.n * self.n - 1]
