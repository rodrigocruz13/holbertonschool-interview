#!/usr/bin/python3
"""
Module used to min ops
"""


def minOperations(n):
    """
    Method that determines if all the boxes can be opened.
    Args:
        n (int): Number.

    Returns:
        x (int): for success,
        0 if it is impossible to achieve
    """

    if (not isinstance(n, int)):
        return 0

    if (n < 2):
        return 0

    res = 0
    i = 2
    while i <= n:
        if n % i == 0:
            res += i
            n = n / i
            i = i - 1
        i = i + 1
    return int(res)
