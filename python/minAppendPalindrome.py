

def check_palindrome(s):
    i, j = 0, len(s) - 1
    while i < j:
        if s[i] != s[j]:
            return False
        i += 1
        j -= 1
    return True


def min_append(s):
    i, j = 0, len(s) - 1
    end = 0
    while i < j:
        if s[i] != s[j]:
            i += 1
        else:
            if check_palindrome(s[i:]):
                end = i
                break
            else:
                i += 1
                continue
    return end

print(min_append("abede"))
print(min_append("aabb"))
print(min_append("abeebe"))
print(min_append("abeebbe"))
print(min_append("abeeebbee"))
