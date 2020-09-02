#!/usr/bin/env python3

def heapsort(iterable):
    num_of_elements = len(iterable) - 1
    leastParent = num_of_elements // 2;
    for i in range(leastParent, -1, -1):
        _sink(iterable, i, num_of_elements)

    for last in range(num_of_elements, 0, -1):
        if iterable[0] > iterable[last]:
            _exch(iterable, 0, last)
            _sink(iterable, 0, last - 1)


def _sink(iterable, parent, last):
    largest = 2 * parent + 1 
    while largest <= last:
        if (largest < last) and (iterable[largest] < iterable[largest + 1]):
            largest += 1
        if iterable[largest] > iterable[parent]:
            _exch(iterable, largest, parent)
            parent = largest
            largest = 2 * parent + 1
        else:
            break


def _exch(iterable, op1, op2):
    temp = iterable[op1]
    iterable[op1] = iterable[op2]
    iterable[op2] = temp

