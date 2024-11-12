#!/usr/bin/python3
"""Returns the perimeter of the island."""

def island_perimeter(grid):
    """Calculate the perimeter of an island in a grid."""
    count = 0
    row = len(grid)
    col = len(grid[0]) if row else 0

    for i in range(row):
        for j in range(col):
            if grid[i][j]:
                # Define neighboring indices
                idx = [(i - 1, j), (i, j - 1), (i, j + 1), (i + 1, j)]
                # Check if each neighbor is within bounds
                check = [
                    1 if k[0] in range(row) and k[1] in range(col) else 0
                    for k in idx
                ]
                # Add to count if a neighbor is water or out of bounds
                count += sum(
                    1 if not r or not grid[k[0]][k[1]] else 0
                    for r, k in zip(check, idx)
                )

    return count
