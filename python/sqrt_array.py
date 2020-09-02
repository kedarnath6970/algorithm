

# Given an sorted array, return an sorted array of squared.

# Input = [0, 1, 2, 3, 4], [1, 3, 5], [-3, -2, -1, 0, 1, 2]
# Output = [0, 1, 4, 9, 16], [1, 9, 25], [9, 4, 1, 0, 1, 4]

# sqrt_neg = [9, 4, 1]
# sqrt_pos = [0, 1, 4]
#
# [9, 4, 1, 0]

def sqrt_array(array):
    sqrt_neg = []
    sqrt_pos = []

    for e in array:
        if e < 0:
            sqrt_neg.append(e * e)
        else:
            sqrt_pos.append(e * e)

    # sqrt_neg = [1, 4, 9]
    sqrt_neg.reverse()
    
    result = []
    p_cur = 0
    n_cur = 0

    while True:
        if p_cur == len(sqrt_pos) or n_cur == len(sqrt_neg):
            break
        if sqrt_pos[p_cur] <= sqrt_neg[n_cur]:
            result.append(sqrt_pos[p_cur])
            p_cur += 1
        else:
            result.append(sqrt_neg[n_cur])
            n_cur += 1

    if p_cur == len(sqrt_pos):
        result.extend(sqrt_neg[n_cur:])
    elif n_cur == len(sqrt_neg):
        result.extend(sqrt_pos[p_cur:])
                
    return result

print(sqrt_array([-3, -2, -1, 0, 1, 2]))

