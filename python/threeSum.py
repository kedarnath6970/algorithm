

import sys

def threeSum(arr, k):
    arr.sort()
    result = []
    for i in range(0, len(arr)-1):
        a = arr[i]
        start = i + 1
        end = len(arr) - 1
        while start < end:
            b = arr[start]
            c = arr[end]
            if a + b + c == k:
                result.append([a, b, c])
                start += 1
                end -= 1
            elif a + b + c > k:
                end -= 1
            else:
                start += 1
    return result

def threeSumClosest(arr, k):
    arr.sort()
    best = [sys.maxsize * -1 , sys.maxsize * -1, sys.maxsize * -1]
    for i in range(0, len(arr)-1):
        a = arr[i]
        start = i + 1
        end = len(arr) - 1
        while start < end:
            b = arr[start]
            c = arr[end]
            if abs(k - (a + b + c)) < abs(k - (best[0] + best[1] + best[2])):
                best = [a, b, c]
            if k > a + b + c:
                start += 1
            else: end -= 1
    return best[0] + best[1] + best[2]

print(threeSumClosest([-1, 2, 1, -4], 1))
