import sys


def find_record_breaker(visitors, max_visitors):
    if len(visitors) == 1:
        if visitors[0] > max_visitors:
            return 1
        return 0

    if len(visitors) >= 2 and (visitors[0] > max_visitors and 
            visitors[0] > visitors[1]):
        max_visitors = visitors[0]
        return find_record_breaker(visitors[1:], max_visitors) + 1
    else:
        max_visitors = max(max_visitors, visitors[0])
        return find_record_breaker(visitors[1:], max_visitors)

    
def main():
    num_tests = int(input("Number of tests: "))
    tests = []
    i = 0
    while i < num_tests:
        num_days = int(input("Number of days: "))
        visitors = [int(x) for x in input("visitors: ").split(' ')]
        assert num_days == len(visitors)
        
        max_visitors = sys.maxsize * -1
        record_breaker = find_record_breaker(visitors, max_visitors)
        print("Case #{}: {}".format(i+1, record_breaker))
        i += 1


if __name__ == "__main__":
    main()
