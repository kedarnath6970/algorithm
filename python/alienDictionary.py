

def alienDictionary(words):
    if len(words) == 0:
        return ""
    max_len = max([len(w) for w in words])
    adj = {}
    head = None
    for i in range(max_len):
        for j in range(len(words)-1):
            src = words[j][i]
            target = words[j+1][i]
            if src != target:
                if src not in adj or target not in adj:
                    if src not in adj:
                        adj[src] = [target]
                    else:
                        adj[src].append(target)
                else:
                    if adj[src] != adj[target]:
                        if src not in adj:
                            adj[src] = [target]
                        else:
                            adj[src].append(target)

                if head is None:
                    head = src
    return adj

print(alienDictionary(["z", "x", "z"]))

        
