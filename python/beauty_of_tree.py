
import random

"""
8 2 3
1 1 3 4 4 3 4
"""

def expected_value(values, n):
    prob = 1 / n
    expected = 0
    for v in values:
        expected += v * prob
    return expected


def calculate_expected_value(a_visited, b_visited, common, n):
    expected_a = expected_value(a_visited, n)
    expected_b = expected_value(b_visited, n)
    common = expected_value(common, n)
    expected =  expected_a + expected_b - (2 * common)
    return expected


def paint_nodes(nodes, node, skip, visited, level=0):
    if skip == level:
        visited.add(node)
        level = 0

    if node > 1:
        paint_nodes(nodes, nodes[node-2], skip, visited, level+1)
    return


def beauty_of_tree(nodes, n, a, b):

    a_node = random.randint(1, n)
    b_node = random.randint(1, n)

    print("Amadea selected: {}".format(a_node))
    print("Bilva selected: {}".format(b_node))

    a_visited = set()
    b_visited = set()
    if a_node == 1:
        a_visited.add(1)

    if a_node > 1:
        a_visited.add(a_node)
        paint_nodes(nodes, a_node, a, a_visited, 0)

    if b_node == 1:
        b_visited.add(1)
    
    if b_node > 1:
        b_visited.add(b_node)
        paint_nodes(nodes, b_node, b, b_visited, 0)
    intersection = a_visited.intersection(b_visited)
    return calculate_expected_value(a_visited, b_visited, intersection, n)


def main():
    num_tests = int(input("Number of tests: "))
    tests = []
    i = 0
    while i < num_tests:
        test_info = [int(x) for x in input("n, A, B: ").split(' ')]
        n, A, B = test_info[0], test_info[1], test_info[2]
        nodes = [int(x) for x in input("nodes: ").split(' ')]
        assert n-1 == len(nodes)

        expected_beauty = beauty_of_tree(nodes, n, A, B)
        print("Case #{}: {}".format(i+1, expected_beauty))
        i += 1


if __name__ == "__main__":
    main()
