#include "slide_line.h"

/**
 * Slides and merges an array of integers
 * @line: pointer to the array of integers.
 * @size: size of the array
 * @direction: move of the slide LEFT or RIGHT
 * Returns 1 on success, 0 on failure.
 */

int slide_line(int *line, size_t size, int direction) {
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT) {
        return 0; // Fail if direction is not valid
    }

    if (direction == SLIDE_LEFT) {
        // Implementation of sliding and merging logic for left direction
        int i, j = 0;
        for (i = 0; i < size; i++) {
            if (line[i] != 0) {
                if (j > 0 && line[j - 1] == line[i]) {
                    line[j - 1] *= 2; // Merge with previous number
                    line[i] = 0; // Clear the current position
                } else {
                    if (line[j] == 0) {
                        line[j] = line[i]; // Move number to the left
                    } else {
                        line[++j] = line[i]; // Move to next position
                    }
                    if (i != j) {
                        line[i] = 0; // Clear the original position
                    }
                }
            }
        }
    } else if (direction == SLIDE_RIGHT) {
        // Implementation for right direction (similar logic as above but reversed)
        int i, j = size - 1;
        for (i = size - 1; i >= 0; i--) {
            if (line[i] != 0) {
                if (j < size - 1 && line[j + 1] == line[i]) {
                    line[j + 1] *= 2; // Merge with next number
                    line[i] = 0; // Clear the current position
                } else {
                    if (line[j] == 0) {
                        line[j] = line[i]; // Move number to the right
                    } else {
                        line[--j] = line[i]; // Move to next position
                    }
                    if (i != j) {
                        line[i] = 0; // Clear the original position
                    }
                }
            }
        }
    }

    return 1; // Return success
}
