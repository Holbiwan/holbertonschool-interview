#!/usr/bin/python3
"""
Summary: Method that determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """
    Determines if all the boxes can be opened

    Args:
        boxes (list of lists): A list of lists where each inner list represents a box and its keys.

    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    num_boxes = len(boxes)
    unlocked = [False] * num_boxes

    unlocked[0] = True

    locked = [0]

    while locked:
        current = locked.pop()
        for key in boxes[current]:
            if 0 <= key < num_boxes and not unlocked[key]:
                unlocked[key] = True
                locked.append(key)

    return all(unlocked)
