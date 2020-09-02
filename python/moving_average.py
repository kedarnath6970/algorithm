
from collections import deque
import itertools


def moving_average(iterable, n=3):
    it = iter(iterable)
    d = deque(itertools.islice(it, n-1))
    d.appendleft(0)
    s = sum(d)
    for elem in it:
        s += elem - d.popleft()
        d.append(elem)
        yield s / n

print(list(moving_average([40, 30, 50, 46, 39, 44])))
