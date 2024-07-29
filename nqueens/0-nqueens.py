#!/usr/bin/python3
"""N Queens algorithm using backtracking."""

import sys


class NQueen:
    """Class to solve the N Queens problem using backtracking."""

    def __init__(self, size):
        """Initialize the board and solutions list."""
        self.size = size
        self.queens_positions = [0] * (size + 1)
        self.solutions = []

    def can_place(self, current_queen, col):
        """Check if the current queen can be placed in the given column.

        Args:
            current_queen (int): The current queen (row) being placed.
            col (int): Column to check for placement.

        Returns:
            bool: True if the queen can be placed, False otherwise.
        """
        for previous_queen in range(1, current_queen):
            if (self.queens_positions[previous_queen] == col or
                    abs(self.queens_positions[previous_queen] - col) ==
                    abs(previous_queen - current_queen)):
                return False
        return True

    def solve(self, queen=1):
        """Recursively try to place queens on the board.
        Args:
            queen (int): The current queen to place, starts at 1.

        Returns:
            list: List where each solution is a list of queen positions.
        """
        if queen > self.size:
            solution = [[i - 1, self.queens_positions[i] - 1]
                        for i in range(1, self.size + 1)]
            self.solutions.append(solution)
        else:
            for col in range(1, self.size + 1):
                if self.can_place(queen, col):
                    self.queens_positions[queen] = col
                    self.solve(queen + 1)

        return self.solutions


# Main execution
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    queen_solver = NQueen(N)
    solutions = queen_solver.solve()

    for solution in solutions:
        print(solution)
