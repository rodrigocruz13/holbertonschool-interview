#!/usr/bin/python3
"""Module used to add two arrays."""


def makeChange(coins, total):
    """[Given a pile of coins of different values, determine the fewest number
            of coins needed to meet a given amount total]

    Args:
            coins ([list]): [list of the values of your the coins]
                              The value of a coin will always be an int > 0
            total ([type]): [description]

    Returns:
            c [int]: (change  [fewest number of coins needed to meet total]
    """

    # verify coins is a list
    c = 0 if (isinstance(coins, list)) else -4

    # verify all coins are integers
    c = c if c == 0 and (all(isinstance(n, int) for n in coins)) else -3

    # verify all coins are positive bigger than 0
    c = c if (c == 0 and all(i > 0 for i in coins)) else -2

    # verify total is a positive integer
    c = 0 if (isinstance(total, int) and total >= 0) else -1

    if c < 0:
        return -1

    if c == 0:
        return 0

    my_coins = sorted(coins, reverse=True)
    money_left = total

    for coin in my_coins:
        while (money_left % coin >= 0 and money_left >= coin):
            c += int(money_left / coin)
            money_left = money_left % coin

    c = c if money_left == 0 else -1

    return c
