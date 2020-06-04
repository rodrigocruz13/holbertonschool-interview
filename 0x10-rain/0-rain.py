#!/usr/bin/python3


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
    - water  : Int
               integer indicating total amount of rainwater retained
    """

    if (arr is not None or len(arr) > 0):

        n = len(arr)
        res = 0

        for i in range(1, n - 1):

            # Find the maximum element on its left
            left = arr[i]
            for j in range(i):
                left = max(left, arr[j])

            # Find the maximum element on its right
            right = arr[i]

            for j in range(i + 1, n):
                right = max(right, arr[j])

            # Update the maximum water
            res = res + (min(left, right) - arr[i])

        return res
    return 0
