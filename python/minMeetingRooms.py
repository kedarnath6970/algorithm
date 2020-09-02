
import heapq


def minMeetingRooms(intervals):
    count = 0
    pq = []
    heapq.heapify(pq)
    for interval in intervals:
        if len(pq) == 0:
            count += 1
            heapq.heappush(pq, interval[1])
        else:
            if interval[0] > pq[0]:
                heapq.heappop(pq)
            else:
                count +=1
            heapq.heappush(pq, interval[1])
    return count

print(minMeetingRooms([(0,30),(5,25),(15,20)]))

