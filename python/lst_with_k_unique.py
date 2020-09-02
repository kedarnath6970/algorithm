import cProfile, pstats, io
from pstats import SortKey

# Python program to find the longest substring with k unique 
# characters in a given string 
MAX_CHARS = 26

# This function calculates number of unique characters 
# using a associative array count[]. Returns true if 
# no. of characters are less than required else returns 
# false. 
def isValid(count, k): 
	val = 0
	for i in range(MAX_CHARS): 
		if count[i] > 0: 
			val += 1

	# Return true if k is greater than or equal to val 
	return (k >= val) 

# Finds the maximum substring with exactly k unique characters 
def kUniques(s, k): 
	u = 0 # number of unique characters 
	n = len(s) 

	# Associative array to store the count 
	count = [0] * MAX_CHARS 

	# Tranverse the string, fills the associative array 
	# count[] and count number of unique characters 
	for i in range(n): 
		if count[ord(s[i])-ord('a')] == 0: 
			u += 1
		count[ord(s[i])-ord('a')] += 1

	# If there are not enough unique characters, show 
	# an error message. 
	if u < k: 
		print ("Not enough unique characters") 
		return

	# Otherwise take a window with first element in it. 
	# start and end variables. 
	curr_start = 0
	curr_end = 0

	# Also initialize values for result longest window 
	max_window_size = 1
	max_window_start = 0

	# Initialize associative array count[] with zero 
	count = [0] * len(count) 

	count[ord(s[0])-ord('a')] += 1 # put the first character 

	# Start from the second character and add 
	# characters in window according to above 
	# explanation 
	for i in range(1,n): 

		# Add the character 's[i]' to current window 
		count[ord(s[i])-ord('a')] += 1
		curr_end+=1

		# If there are more than k unique characters in 
		# current window, remove from left side 
		while not isValid(count, k): 
			count[ord(s[curr_start])-ord('a')] -= 1
			curr_start += 1

		# Update the max window size if required 
		if curr_end-curr_start+1 > max_window_size: 
			max_window_size = curr_end-curr_start+1
			max_window_start = curr_start 

	print ("Max substring is : " + s[max_window_start:max_window_start + max_window_size] 
	+ " with length " + str(max_window_size)) 

# Driver function 
input_str = "aabacbebebe"
k = 3


pr = cProfile.Profile()
pr.enable()

kUniques(input_str, k) 

pr.disable()

s = io.StringIO()
sortby = SortKey.CUMULATIVE
ps = pstats.Stats(pr, stream=s).sort_stats(sortby)
ps.print_stats()
print(s.getvalue())


def findLstWithKUnique(input_str, k):
    begin = 0
    end = 1
    max_string = None
    while end < len(input_str) + 1:
        char_set = set(input_str[begin: end])
        if len(char_set) == k:
            if max_string is None:
                max_string = input_str[begin:end]
            else:
                if len(input_str[begin:end]) > len(max_string):
                    max_string = input_str[begin:end]
        elif len(char_set) > k:
            begin += 1
            if len(input_str[begin:end]) > len(max_string):
                max_string = input_str[begin: end]

        print(len(char_set))
        end += 1

    return max_string


input_str = "aabacbebebe"
k = 3

pr = cProfile.Profile()
pr.enable()

max_string = findLstWithKUnique(input_str, k)

pr.disable()
print("Max string: {}".format(max_string))

s = io.StringIO()
sortby = SortKey.CUMULATIVE
ps = pstats.Stats(pr, stream=s).sort_stats(sortby)
ps.print_stats()
print(s.getvalue())
