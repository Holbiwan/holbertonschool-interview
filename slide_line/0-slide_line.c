#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers containing size elements
 * @size: the number of elements in the array
 * @direction: the direction to slide and merge (SLIDE_LEFT, SLIDE_RIGHT)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction) {
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT) {
        return 0; // Validate direction
    }

    if (direction == SLIDE_LEFT) {
        size_t i = 0, j = 0;

        // Move non-zero elements to the front
        for (i = 0; i < size; i++) {
            if (line[i] != 0) {
                if (j != i) {
                    line[j] = line[i];
                    line[i] = 0;
                }
                j++;
            }
        }

        // Merge consecutive equal elements
        for (i = 0; i < size - 1; i++) {
            if (line[i] != 0 && line[i] == line[i + 1]) {
                line[i] *= 2;
                line[i + 1] = 0;
                i++; // Skip the next element since it's already merged
            }
        }

        // Move non-zero elements to the front again after merging
        j = 0;
        for (i = 0; i < size; i++) {
            if (line[i] != 0) {
                if (j != i) {
                    line[j] = line[i];
                    line[i] = 0;
                }
                j++;
            }
        }
    }

    return 1; // Success
}
