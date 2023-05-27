from typing import List


class Interval:
    def __init__(self, l, r):
        self.l = l
        self.r = r
        self.active = True


class SummaryRanges:
    def __init__(self):
        self.interval_id_by_value = dict()
        self.intervals = []

    def addNum(self, value: int) -> None:
        if value in self.interval_id_by_value:
            return
        l_id = self.interval_id_by_value.get(value - 1, None)
        r_id = self.interval_id_by_value.get(value + 1, None)
        if l_id is not None and r_id is not None:
            self.intervals[l_id].r = self.intervals[r_id].r
            self.interval_id_by_value[value] = l_id
            for idx in range(self.intervals[r_id].l, self.intervals[r_id].r + 1):
                self.interval_id_by_value[idx] = l_id
            self.intervals[r_id].active = False
        elif l_id is not None:
            self.intervals[l_id].r += 1
            self.interval_id_by_value[value] = l_id
        elif r_id is not None:
            self.intervals[r_id].l -= 1
            self.interval_id_by_value[value] = r_id
        else:
            self.intervals.append(Interval(value, value))
            self.interval_id_by_value[value] = len(self.intervals) - 1

    def getIntervals(self) -> List[List[int]]:
        pairs = [
            (interval.l, interval.r) for interval in self.intervals if interval.active
        ]
        return sorted(pairs)


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()
