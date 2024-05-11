#!/usr/bin/env python3
"""0-lockboxes.py"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""
    keys = [0]
    idx = 0
    while idx < len(keys):
        current_key = keys[idx]
        for new_key in boxes[current_key]:
            if new_key not in keys and new_key < len(boxes):
                keys.append(new_key)
        idx += 1
    return len(keys) == len(boxes)
