#!/usr/bin/python3
"""
lists of integers representing the Pascal's triangle
"""


def pascal_triangle(n):
    """
    lists of integers representing Pascal's triangle
    """
    if type(n) is not int:
        raise TypeError("n must be an integer")
    triangle = []
    if n <= 0:
        return triangle
    previous = [1]
    for row_index in range(n):
        rowlist = []
        if row_index == 0:
            rowlist = [1]
        else:
            for i in range(row_index + 1):
                if i == 0:
                    rowlist.append(0 + previous[i])
                elif i == (row_index):
                    rowlist.append(previous[i - 1] + 0)
                else:
                    rowlist.append(previous[i - 1] + previous[i])
        previous = rowlist
        triangle.append(rowlist)
    return triangle
