

class SpreadSheet:
    def __init__(self):
        self.sp = {}

    def set_value(self, cid, val):
        cell_values = None
        if val.startswith('='):
            val = val[1:]
            op_index = val.find('+')
            op1, op2 = val[:op_index], val[op_index+1:]
            cell_values = [op1, op2]
        else:
            cell_values = [val]
        self.sp[cid] = cell_values

    def get_value(self, cid):
        val = 0
        if cid not in self.sp:
            return val
        else:
            for v in self.sp[cid]:
                if v.isdigit():
                    val += int(v)
                else:
                    val += int(self.get_value(v))
        return val
    
    def set_cell(self, cid, val):
        self.set_value(cid, val)

    def get_cell(self, cid):
        return self.get_value(cid)


sp = SpreadSheet()
sp.set_cell('C1', '45')
sp.set_cell('B1', '10')
sp.set_cell('A1', '=C1+B1')
sp.set_cell('D1', '=A1+20')

print(sp.get_cell('C1'))
print(sp.get_cell('A1'))
print(sp.get_cell('D1'))

sp.set_cell('B1', '100')
print(sp.get_cell('A1'))
print(sp.get_cell('D1'))
