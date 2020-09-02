
def isMatch(s: str, p: str) -> bool:
    pattern = []
    w_left = -1

    for i in range(len(p)):
        if p[i] != '*':
            if w_left == -1:
                pattern.append(p[i])
            else:
                pattern.append(p[w_left])
                w_left = -1
                pattern.append(p[i])
        else:
            if w_left == -1:
                w_left = i
            w_left = i

    if w_left != -1:
        pattern.append(p[w_left])
    pattern = ''.join(pattern)
    print("src: {}".format(s))
    print("pattern: {}".format(pattern))
    return isMatchWrapper(s, pattern)


def isMatchWrapper(s: str, p: str) -> bool:

    if(not s and not p):
        return True

    if(not s and p == '*'):
        return True

    if(s and not p) or (not s and p):
        return False

    if(p[0] == '*'):
        return isMatchWrapper(s, p[1:]) or isMatchWrapper(s[1:], p)
    elif(p[0] == '?'):
        return isMatchWrapper(s[1:], p[1:])
    else:
        if(s[0] == p[0]):
            return isMatchWrapper(s[1:], p[1:])
        else:
            return False

src="babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb"
pattern="b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a"
#src = "ho"
#pattern = "ho**"
if(isMatch(src, pattern)):
    print("Matching")
else:
    print("Non-matching")
