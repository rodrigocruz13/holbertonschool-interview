#!/usr/bin/python3
"""
Module used to
"""


def rain(arr):
    """
    Given a list of non-negative integers representing walls of width 1,
    calculate how much water will be retained after it rains.

    Assume that the ends of the list (before index 0 and after index
    walls[-1]) are not walls, meaning they will not retain water.
    If the list is empty return 0.

    Arguments
    ---------
    - walls  : list
               list of non-negative integers.

    Returns
    -------
    - rain  : Int
               integer indicating total amount of rainwater retained
    """

    if (arr is None):
        return 0

    if not (isinstance(arr, list)):
        return 0

    n = len(arr)
    if (n < 2):
        return 0

    if not all(isinstance(n, int) for n in arr):  # any no integer
        return 0

    if (len([num for num in arr if num < 0]) > 0):  # any negative
        return 0

    rain = 0
    for i in range(1, n - 1):

        # Find the maximum element on its left
        left = arr[i]
        for j in range(i):
            left = max(left, arr[j])

        # Find the maximum element on its right
        right = arr[i]
        for j in range(i + 1, n):
            right = max(right, arr[j])

        # Update the maximum of rain collected
        rain += (min(left, right) - arr[i])

    return rain
