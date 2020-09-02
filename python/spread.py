

# Example spreadsheet
#     A        B        C
# 1   0        4        5
# 2   1        B1/2    
# 3   A1+A2    6 .      SUM(A1:C2)
        

get_references('=SUM(A1:C2)')
['A1', 'A2', 'A3'...]
    
f = get_function('=SUM(A1:C2)')
f(['1', '2', '3', '4'...])
    
# helpers
def is_numeric(cell):
    """Returns True if cell is numeric
    
    >>> is_numeric('5')
    True
    
    >>> is_numeric('C1-5')
    False
    
    """
    pass

def get_references(cell):
    """Returns a list of cell references as a list of strings.

    Args:
        cell (str): cell contents
    Returns:
        list: list of cell coordinates as strings

    Example:

    >>> get_references('=A1+B1')
    ['A1', 'B1']
    """
    pass

def get_function(cell):
    """ 
    Given the contents of a non-numeric cell, return a callable corresponding
    to the formula in the cell. This callable takes one argument, a list of numeric
    cell values corresponding to the cells needed by the formula.

    (i.e., signature is Str -> (List -> Int))

    Example:

    >>> get_function('=A1+B1')(['1', '2'])
    '3'
    >>> f = get_function(‘=A1+B1’)
    >>> f([‘1’, ‘2’])
    ‘3’
    """
    
# sheet = {‘A1’: ‘0’, ‘A2’: ‘1’, ‘A3’: ‘=A1+A2’, ‘B1’: ‘4’, ... }  
# sheet = {‘A1’: ‘=A2+A3’, ‘A2’: ‘1’, ‘A3’: ‘0’, ‘B1’: ‘4’, ... }  
# sheet = {'A1': '1', 'A2':....} 
# sheet = {'A1': '=A2', 'A2': '=A3', 'A3': '4'}
# sheet = {'A1': '=A2+A3', 'A2': '=A4+A5', 'A3': ='A5+A6',
# 'A4': '4', 'A5': '5', 'A6': '6'}

get_function('1') -> f() -> '1'

class Cell:
    def __init__(self):
        self.val = None
        self.operator = None
        self.args = []

    def set_value(self, val):
        if is_digit(val):
            self.val = val
        else:
            self.formula = val

    def get_value(self):
        if self.val is not None and is_digit(self.val):
            return self.val
        return self.operator(self.args)

def calculate_cell(sheet, c_id):
    if is_numeric(sheet[c_id]):
        return sheet[c_id]
    
    visited = []
    v_args = get_references(sheet[c_id])
    for c_id in v_args:
        visited.append(calculate_cell(c_id))
    f = get_function(v)
    return f(visited)


def eval(sheet):
    updated_sheet = {}
    for k in sheet.keys():
        if not is_numeric(sheet[k]):
            updated_sheet[k] = calculate_cell(k)
    return updated_sheet
