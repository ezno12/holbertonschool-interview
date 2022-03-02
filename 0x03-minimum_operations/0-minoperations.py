#!/usr/bin/python

"""
module containing function to calc min operations
"""


def minOperations(n):
    """
    calc min operations
    """

    if n <= 1:
        return 0
    else:
        prime = prime_numbers(n)
        if prime == []:
            return 0
        else:
            return sum(prime)


def prime_numbers(n):
    """
    calc
    """

    if n < 2:
        return []

    prime = []
    i = 2
    while i <= n:
        if n % i == 0:
            prime.append(i)
            n /= i
        else:
            i += 1
    return prime