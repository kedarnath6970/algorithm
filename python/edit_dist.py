

import itertools
import numpy as np
import sys

"""
This implementation follows dynamic programming with match, deletion,
and insertion based on associated scores.
Time and space complexisity is O(n^2) 
"""
def get_distance(s1, s2, match_cost = 5, mis_cost = -4, gap_cost = -7):
    matrix = np.zeros((len(s1) + 1, len(s2) + 1), np.int)

    for i, j in itertools.product(range(1, matrix.shape[0]), range(1,
        matrix.shape[1])):
        m_cost = match_cost
        if s1[i - 1] != s2[j - 1]:
            m_cost = mis_cost
        match = matrix[i - 1, j - 1] + m_cost
        delete = matrix[i - 1, j] + gap_cost
        insert = matrix[i, j - 1] + gap_cost
        matrix[i, j] = max(match, delete, insert)
    return matrix

"""
Given a list of calculated scores, print sequences with maximum score.
"""
def print_similarity(qseq, seqs, scores):
    max_score = -1
    for _, score in scores:
        if score > max_score:
            max_score = score

    print("The query sequence is:")
    print(qseq + "\n")
    for seq, score in zip(seqs, scores):
        if score[1] == max_score:
            print("The most similar sequence are:\n")
            print(seq)
            print("The similarity score is: {}\n".format(score[1]))


def find_similar_seq(query, seqs):
    scores = []
    for i, s in enumerate(seqs):
        score = get_distance(query, s)
        scores.append([i, score[-1][-1]])
    print_similarity(query, seqs, scores)

"""
Hanlde ill-formatted sequence name and sequence itself.
"""
def check_input_format(seq_name, seq):
    if not seq_name.startswith('>'):
        print("Seq name should starts with >")
        sys.exit()
    if len(seq) == 0:
        print("Sequence lenght should not be zero.")
        sys.exit()


def main(argv):
    qseq = None
    seqs = []
    qname = input("Qname:")
    qseq = input().strip()
    input()
    if not qname.startswith('>'):
        print("Query name should start with >")
        sys.exit()

    seq_name = input()
    seq = input().strip()
    check_input_format(seq_name, seq)
    seqs.append(seq)
    input()
    while True:
        seq_name = input()
        if len(seq_name) == 0:
            break
        seq = input().strip()
        check_input_format(seq_name, seq)
        input()
        seqs.append(seq)

    find_similar_seq(qseq, seqs)

if __name__ == "__main__":
    main(sys.argv[1:])

