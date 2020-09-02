
import heapq

class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, other):
        return self.x ** 2 + self.y ** 2 < other.x ** 2 + other.y ** 2


def kClosest(points, K):
    pq = []
    for p in points:
        pq.append(Point(p[0], p[1]))
    heapq.heapify(pq)
    
    res = []
    for i in range(K):
        q = heapq.heappop(pq)
        res.append([q.x, q.y])
    return res

print(kClosest([[1,3],[-2,2]], 1))
print(kClosest([[3,3],[5,-1],[-2,4]], 2))
