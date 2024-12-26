#!/usr/bin/python3

""" Prime Game """


def is_prime(n):
    """Checks if a number given n is a prime number"""
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def calculate_primes(n, primes):
    """Calculate all primes up to n and store them """
    top_prime = primes[-1]
    if n > top_prime:
        for i in range(top_prime + 1, n + 1):
            if is_prime(i):
                primes.append(i)


def isWinner(x, nums):
    """
    Determine the winner of the prime game.

    Args:
        x (int): Number of rounds.
        nums (list of int): Array of n values for each round.

    Returns:
        str: Name of the player that won the most rounds, or None if a tie.
    """
    if x < 1 or not nums:
        return None

    players_wins = {"Maria": 0, "Ben": 0}
    primes = [0, 0, 2]  # Prepopulate with first prime

    # Precompute primes up to the maximum number in nums
    calculate_primes(max(nums), primes)

    for n in nums:
        sum_options = sum(1 for i in primes[:n + 1] if i != 0 and i <= n)

        # Determine winner for this round
        if sum_options % 2 == 1:
            players_wins["Maria"] += 1
        else:
            players_wins["Ben"] += 1

    if players_wins["Maria"] > players_wins["Ben"]:
        return "Maria"
    elif players_wins["Ben"] > players_wins["Maria"]:
        return "Ben"

    return None
