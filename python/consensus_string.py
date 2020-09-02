
from collections import deque
import sys
import time


def hamm_distance(chaine1, chaine2):
    return sum(c1 != c2 for c1, c2 in zip(chaine1, chaine2))

def hamming_distance(seq1, seq2):
    if len(seq1) != len(seq1):
        raise ValueError("Sequence length should be same.")
    h_dist = 0
    for s1, s2 in zip(seq1, seq2):
        if s1 != s2:
            h_dist +=1
    return h_dist


def find_min_consensus(con_errors):
    min_error = sys.maxsize
    consensus_index = []
    for i, e in enumerate(con_errors):
        if e <= min_error:
            min_error = e
            consensus_index.append(i)
    return consensus_index
    

def count_bases(bases):
    freq = {}
    for b in bases:
        if b not in freq:
            freq[b] = 0
        freq[b] += 1
    return freq.keys()


def get_max_base(freq):
    max_freq = -1
    max_bases = []
    for k, v in freq.items():
        if v > max_freq:
            max_freq = v
    for k, v in freq.items():
        if v == max_freq:
            max_bases.append(k)
    return max_bases


def get_consensus_string(seqs):
    base_string = None
    for i in range(len(seqs[0])):
        bases = [seq[i] for seq in seqs]
        max_bases = count_bases(bases)
        #max_bases = get_max_base(freq)
        if not base_string:
            base_string = deque(max_bases)
        else:
            dq_len = len(base_string)
            while dq_len > 0:
                bstr = base_string.popleft()
                for b in max_bases:
                    base_string.append(bstr+b)
                dq_len -= 1
    return base_string


def find_consensus_error(consensus_seqs, seqs):
    consensus_error = []
    for con_seq in consensus_seqs:
        con_error = 0
        for i in range(len(seqs)):
            dist = hamm_distance(con_seq, seqs[i])
            con_error += dist
        consensus_error.append(con_error)
    
    index = find_min_consensus(consensus_error)
    if len(index) == 1:
        return (consensus_seqs[0], consensus_error[index[0]])
    else:
        seq_info = list([(consensus_seqs[i], consensus_error[i]) for i in index])
        seq_info.sort(key=lambda x: x[0])
        return seq_info[0]
                

def main(argv):
    start_time = time.time()
    print("start_time: {}".format(start_time))
    num_tests = int(input("Num tests: "))
    n = num_tests
    test_seqs = []
    while n > 0:
        seq_info = input("num_seq seq_len: ")
        seq_info = seq_info.split(' ')
        assert len(seq_info) == 2
        num_seqs, seq_len = int(seq_info[0]), int(seq_info[1])
        seqs = [input() for i in range(num_seqs)]
        for seq in seqs:
            assert seq_len == len(seq)
        test_seqs.append(seqs)
        print("Number of tests: {}".format(num_tests))
        print("Number of sequences: {}".format(num_seqs))
        print("Sequence length: {}".format(seq_len))
        print("seqs: {}".format(seqs))
        n -= 1
    n = 0
    while n < num_tests:
        consensus_str = get_consensus_string(test_seqs[n])
        seq_info = find_consensus_error(consensus_str, test_seqs[n])
        print("Consensus seq: {}".format(seq_info[0]))
        print("Consensus error: {}".format(seq_info[1]))
        n += 1
    end = time.time()
    print("Time being taken:L {}".format(time.time() - start_time))

if __name__ == "__main__":
    main(sys.argv[1:])
