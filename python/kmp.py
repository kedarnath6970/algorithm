
"""
src = {"minecraftgame", "intelligent", "innercrafttalent", "knife", "scissor", "stonecrafter"}
key = "craft"

result = {"minecraftgame", innercrafttalent", "stonecrafter"}

0. Initialize output = []
1. Loop each string of the src array
2. For each position of the string
    compare ith character the string and jth char of key
    if it matches:
        if j == len(key) - 1:
            store this string to the output array
            break
        increase j
    else
        reset j to 0
"""

import time

def find_matching_string(words, key):
    start = time.time()
    output = []
    for word in words:
        j = 0
        for i, c in enumerate(word):
            if c == key[j]:
                if j == len(key) - 1:
                    output.append(word)
                    break
                else:
                    j += 1
            else:
                j = 0
    end = time.time()
    print("Time taken: {}".format(end - start))
    return output

def find_matching_string_with_kmp(words, key):
    start = time.time()
    output = []
    for word in words:
        if key in word:
            output.append(word)
    end = time.time()
    print("Time taken: {}".format(end - start))
    return output


src = ["minecraftgame", "intelligent",
        "innercrafttalent", "knife",
        "scissor", "stonecrafter"]
key = "craft"
print("result: {}".format(find_matching_string_kmp(src, key)))
