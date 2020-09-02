# Problem: Given a list of "name elements", e.g. "alex thirty" or "dong forty-nine"
# return the list, sorted first by name, then by the numerical value of the number

# alex two
# bob five

# one
# one-hundred-million


# alex two
# alex ten

# bob twenty-one
# bob twenty


from functools import cmp_to_key

lookup = {
    'one': 1,
    'two': 2,
    'three': 3,
    'four': 4,
    'five': 5,
    'six': 6,
    'seven': 7,
    'eight': 8,
    'nine': 9,
    'ten': 10,
    'eleven': 11,
    'twelve': 12,
    'thirteen': 13,
    'fourteen': 14,
    'fifteen': 15,
    'sixteen': 16,
    'seventeen': 17,
    'eighteen': 18,
    'nineteen': 19,
    'twenty': 20,
    'thirty': 30,
    'forty': 40,
    'fifty': 50,
    'sixty': 60,
    'seventy': 70,
    'eighty': 80,
    'ninety': 90,
}

    
def convert_string_to_num(num_string):
    major = num_string
    minor = 0
    if num_string.find('-') > 0:
        ages = num_string.split('-')
        print(ages)
        major, minor = ages[0], ages[1]

    num_age = 0
    if major in lookup:
        num_age += lookup[major]
    if minor:
        num_age += lookup[minor]
    return num_age
    
    
def compare(a, b):
    a_name, a_age = a.split(' ')
    b_name, b_age = b.split(' ')
    if a_name == b_name:
        if convert_string_to_num(a_age) <= convert_string_to_num(b_age):
            return True
        else:
            return False
    else:
        return a_name < b_name
    
    
def sorted_names(name_elements):
    name_elements.sort(key=cmp_to_key(lambda x, y: compare(x, y)))
    return name_elements

print(sorted_names(["dong forty-nine", "dong ten", "alex thirty"]))
