#!/usr/bin/python3
"""
Module to rotate a 2D matrix by 90 degrees.
"""


def rotate_2d_matrix(matrix):
    """
    Rotates a square 2D matrix 90 degrees clockwise, in place.

    Parameters
    ----------
    - matrix : list of lists of integers

    Returns
    -------
    None
    """
    
    # Copy the original matrix for reference
    copy = matrix[:]

    for i in range(len(matrix)):
        # Extract the i-th column from the copy
        col_i = [row[i] for row in copy]
        
        # Replace the i-th row with the reversed column
        matrix[i] = col_i[::-1]
