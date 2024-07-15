#include "slide_line.h"

int slide_line(int *line, size_t size, int direction) {
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT) {
        return 0;
    }

    size_t i, j;  // Modifier ici pour utiliser size_t au lieu de int

    if (direction == SLIDE_LEFT) {
        for (i = 0; i < size; i++) {
            if (line[i] != 0) {
                j = i;
                // Trouver la position j pour placer line[i]
                while (j > 0 && line[j - 1] == 0) {
                    j--;
                }
                if (j > 0 && line[j - 1] == line[i]) {
                    line[j - 1] *= 2;
                    line[i] = 0;
                } else if (i != j) {
                    line[j] = line[i];
                    line[i] = 0;
                }
            }
        }
    } else {  // SLIDE_RIGHT
        for (i = size - 1; i != (size_t)-1; i--) {
            if (line[i] != 0) {
                j = i;
                // Trouver la position j pour placer line[i]
                while (j < size - 1 && line[j + 1] == 0) {
                    j++;
                }
                if (j < size - 1 && line[j + 1] == line[i]) {
                    line[j + 1] *= 2;
                    line[i] = 0;
                } else if (i != j) {
                    line[j] = line[i];
                    line[i] = 0;
                }
            }
        }
    }

    return 1; // Return success
}
