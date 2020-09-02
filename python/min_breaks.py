alien_pitches = ['A', 'B', 'C', 'D']

def penalty(pitches, i, jj, j):
    if pitches[i-1] < pitches[i] and jj > j:
        return 1
    return 0


def find_min_breaks_dp(pitches):
    DP = [[0 for j in range(len(alien_pitches))] for i in range(len(pitches))]
    min_breaks = 0
    for i in range(len(pitches)):
        for j in range(len(alien_pitches)):
            DP[i][j] = min(
                [DP[i-1][jj] + penalty(pitches, i, jj, j) for jj in range(0, 4)])
        print("penalty {}: {}".format(i, DP[i]))
    return min_breaks


def find_min_breaks(pitches, num_pitches):
    upCount = 0
    downCount = 0
    violations = 0
    pitches = [pitches[i] for i in range(0, num_pitches)
            if i == 0 or pitches[i - 1] != pitches[i]]
    for i in range(1, len(pitches)):
        if pitches[i] > pitches[i - 1]:
            upCount += 1
            downCount = 0
        else:
            downCount += 1
            upCount = 0
        if upCount > 3 or downCount > 3:
            violations += 1
            upCount = downCount = 0
    return violations


def main():
    num_tests = int(input("Number of tests: "))
    tests = []
    i = 0
    while i < num_tests:
        num_notes = int(input("Number of notes: "))
        notes = [int(x) for x in input("notes: ").split(' ')]
        assert num_notes == len(notes)

        min_breaks = find_min_breaks(notes, num_notes)
        print("Case #{}: {}".format(i+1, min_breaks))
        i += 1


if __name__ == "__main__":
    main()
