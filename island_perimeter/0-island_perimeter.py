#!/usr/bin/python3
"""
Module to calculate the perimeter of an island in a grid.
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island represented in a grid.

    The grid is a list of lists where '1' represents land and '0' represents
    water. The function calculates the perimeter by counting the borders of
    each land cell that are adjacent to water or at the edge of the grid.

    Args:
        grid (list of lists of int): A rectangular grid where each cell is
                                     either 0 (water) or 1 (land).

    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                # Check each possible sides (top, bottom, left, right)
                # and add to perimeter if there's water

                # Check top
                if row == 0 or grid[row - 1][col] == 0:
                    perimeter += 1
                # Check bottom
                if row == rows - 1 or grid[row + 1][col] == 0:
                    perimeter += 1
                # Check left
                if col == 0 or grid[row][col - 1] == 0:
                    perimeter += 1
                # Check right
                if col == cols - 1 or grid[row][col + 1] == 0:
                    perimeter += 1

    return perimeter
