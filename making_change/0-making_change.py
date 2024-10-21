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

    coins.sort(reverse=True)
    num_coins = 0

    for coin in coins:
        if coin <= total:
            num_coins += total // coin
            total %= coin

    if total == 0:
        return num_coins
    return -1

if __name__ == "__main__":
    print(makeChange([1, 2, 25], 37))  # Expected output: 7
    print(makeChange([1256, 54, 48, 16, 102], 1453))  # Expected output: -1
