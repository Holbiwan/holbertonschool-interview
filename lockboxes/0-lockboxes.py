#!/usr/bin/env python3
"""0-lockboxes.py"""


def canUnlockAll(boxes):
    """_summary_

    Args:
        boxes (_type_): _description_

    Returns:
        _type_: _description_
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
