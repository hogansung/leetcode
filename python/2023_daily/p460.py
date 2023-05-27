import queue


class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.key_count = 0
        self.version_id = 0
        self.pq = queue.PriorityQueue()
        self.version_id_by_key = dict()
        self.use_count_by_key = dict()
        self.value_by_key = dict()

    def get(self, key: int) -> int:
        self.__clean__()
        if key not in self.value_by_key:
            return -1
        self.version_id += 1
        self.use_count_by_key[key] += 1
        self.version_id_by_key[key] = self.version_id
        self.pq.put((self.use_count_by_key[key], self.version_id_by_key[key], key))
        return self.value_by_key[key]

    def put(self, key: int, value: int) -> None:
        self.__clean__()
        self.version_id += 1
        if key not in self.value_by_key:
            if self.key_count == self.capacity:
                _, _, to_be_delete_key = self.pq.get(0)
                del self.value_by_key[to_be_delete_key]
                self.key_count -= 1
            self.use_count_by_key[key] = 0
            self.key_count += 1
        self.value_by_key[key] = value
        self.use_count_by_key[key] += 1
        self.version_id_by_key[key] = self.version_id
        self.pq.put((self.use_count_by_key[key], self.version_id_by_key[key], key))

    def __clean__(self):
        while self.pq.qsize() > 0:
            _, version_id, to_be_delete_key = self.pq.queue[0]
            if (
                to_be_delete_key not in self.value_by_key
                or version_id < self.version_id_by_key[to_be_delete_key]
            ):
                _ = self.pq.get()
            else:
                break


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
