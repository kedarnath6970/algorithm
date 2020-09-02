
import sys
import time
from collections import deque

def update_queue(queue, item):
    for q in queue:
        q[0]  -= item[0]
        q[1] -= item[1]


def find_converved_region(s1, s2, p):
    longest_len = 0
    mat = 0
    mis = 0
    total = 0
    k = 0
    q = deque()
    for c1, c2 in zip(s1, s2):
        if c1 == c2:
            mat += 1
        else:
            mis += 1
            q.append([mat, mis])
        total += 1
    print("total: {}, mat: {}, mis: {}".format(total, mat, mis))
    if mat == 0:
        return "No solution"
    elif mat == 1:
        return 1
    else:
        error = int((mis / total) * 100)
        print("error: {}".format(error))
        if error < p:
            return len(s1)
        else:
            while len(q) > 0:
                item = q.popleft()
                update_queue(q, item)
                mis -= item[1]
                total -= (item[0] + item[1])
                error = int((mis / total) * 100)
                print("total: {}, mat: {}, mis: {}, error: {}".format(total, item[0], item[1], error))
                if error <= p:
                    if longest_len < total:
                        longest_len = total
    return longest_len




print(find_converved_region('ACTGGATACGTAAA', 'ACCGGTAACGTGAA', int(25)))


"""
def main(argv):
    start_time = time.time()
    print("start_time: {}".format(start_time))
    test_info = input("Seq_len percentage: ")
    n, p = test_info.split()
    while int(n) != 0:
        seq1 = input("seq1: ")
        seq2 = input("seq2: ")
        assert len(seq1) == int(n) and len(seq2) == int(n)
        print("Find the longest conserved sequence ")
        print("Seq len: {}".format(n))
        print("Allowed perc: {}".format(p))
        print("Seq1: {}".format(seq1))
        print("Seq2: {}".format(seq2))

        print(find_converved_region(seq1, seq2, int(p)))

        test_info = input("Seq_len percentage: ")
        n, p = test_info.split()
   
    end = time.time()
    print("Time being taken:L {}".format(time.time() - start_time))

if __name__ == "__main__":
    main(sys.argv[1:])

"""
