#!/usr/bin/python3
"""
Task 0. Change comes from within
"""


def makeChange(coins, total):
    """
    Given a set of coin denominations, determine the minimum number of coins
    required to make a given amount.

    Args:
        coins (list of ints): a list of the coin denominations
        total (int): the total amount of change to make

    Return:
        int: the minimum number of coins needed to make the total,
             or -1 if the total cannot be met by any number of coins
    """
    if total <= 0:
        return 0

    placeholder = total + 1

    memo = {0: 0}

    for i in range(1, total + 1):
        memo[i] = placeholder

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            memo[i] = min(memo[current] + 1, memo[i])

    if memo[total] == total + 1:
        return -1

    return memo[total]
