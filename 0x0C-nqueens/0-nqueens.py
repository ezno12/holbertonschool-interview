#!/usr/bin/python3
"""
N-queen problem
"""
import sys


def nqueen(t_arr, arr, col, i, n):
    """
    Find all posibles solution for N-queen problem
    """
    if (i > n):
        arr.append(t_arr[:])
        return arr

    for j in range(n + 1):
        if i == 0 or ([i - 1, j - 1] not in t_arr and
                      [i - 1, j + 1] not in t_arr and
                      j not in col):
            if i > 1:
                dia = 0
                for k in range(2, i + 1):
                    if ([i - k, j - k] in t_arr) or ([i - k, j + k] in t_arr):
                        dia = 1
                        break
                if dia:
                    continue
            t_arr.append([i, j])
            col.append(j)
            nqueen(t_arr, arr, col, i + 1, n)
            col.pop()
            t_arr.pop()

    return arr


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        n = int(sys.argv[1])
    except:
        print("N must be a number")
        exit(1)

    if not isinstance(n, int):
        print("N must be a number")
        exit(1)

    elif n < 4:
        print("N must be at least 4")
        exit(1)

    queens = nqueen([], [], [], 0, n - 1)
    for i in queens:
        print(i)
