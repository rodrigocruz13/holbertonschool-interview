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
            change [int]: [fewest number of coins needed to meet total]
    """

    # verify total is a positive integer
    change = 0 if (isinstance(total, int) and total >= 0) else -3

    # verify all coins are integers
    change = change if all(isinstance(n, int) for n in coins) else -2

    # verify all coins are positive
    change = change if (change >= 0 and all(i > 0 for i in coins)) else -1

    if change < 0:
        return -1

    my_coins = sorted(coins, reverse=True)
    money_left = total

    for coin in my_coins:
        while (money_left % coin >= 0 and money_left >= coin):
            change += int(money_left / coin)
            money_left = money_left % coin

    change = change if money_left == 0 else -1

    return change
