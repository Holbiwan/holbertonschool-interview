#!/usr/bin/python3
"""Test algorithm project"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island in a grid.

    Args:
        grid (list of list of int): A rectangular grid where:
            - 0 represents water,
            - 1 represents land.
            - Each cell is a square with side length 1.
            - Cells are connected horizontally/vertically, not diagonally.
            - Grid is surrounded by water, has only one island (or none),
            and the island does not contain "lakes" (water surrounded by land)
    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4

                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 1
                if i < rows - 1 and grid[i + 1][j] == 1:
                    perimeter -= 1
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 1
                if j < cols - 1 and grid[i][j + 1] == 1:
                    perimeter -= 1

    return perimeter
