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
    my_coins = sorted(coins, reverse=True)
    money_left = total
    change = 0

    for coin in my_coins:
        while (money_left % coin >= 0 and money_left >= coin):
            change += int(money_left / coin)
            money_left = money_left % coin

    change = change if money_left == 0 else -1

    return change
