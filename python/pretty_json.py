
from collections import deque

def get_pretty_json(src):
    stack = deque()
    i = 0
    indent = 0
    start =  i
    print(" " * 4 * indent + src[i])
    i += 1
    start = i
    indent += 1
    while i < len(src):
        if src[i] == "{":
            print(" " * 4 * indent + src[start:i+1])
            indent += 1
            start = i + 1
        elif src[i] == "[":
            print(" " * 4 * indent + src[start:i+1])
            indent += 1
            start = i + 1
        elif src[i] == "}":
            print(" " * 4 * indent + src[start: i])
            indent -= 1
            print(" " * 4 * indent + src[i])
            start = i + 1
        elif src[i] == "]":
            print(" " * 4 * indent + src[start: i])
            indent -= 1
            print(" " * 4 * indent + src[i])
            start = i + 1
        elif src[i] == ",":
            print(" " * 4 * indent + src[start:i+1])
            start = i + 1
        i += 1
        

input_str = str("""{"id": "0001", "type": "donut","name": "Cake","ppu":0.55, "batters":{"batter":[{ "id": "1001", "type": "Regular" },{"id": "1002", "type": "Chocolate" }]},"topping":[{ "id": "5001","type": "None" },{ "id": "5002", "type": "Glazed"}]}""")
input_str = input_str.replace(' ', '')
get_pretty_json(input_str)
