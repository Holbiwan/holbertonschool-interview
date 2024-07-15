#include "slide_line.h"

/**
 * reverse - Reverses the order of elements in an array.
 * @line: Pointer to the array.
 * @size: Number of elements.
 * Description: Swaps elements from start to end, moving towards the center.
 */
void reverse(int *line, size_t size)
{
    size_t a = 0;
    size_t b = size - 1;
    while (a < b)
    {
        int temp = line[a];
        line[a] = line[b];
        line[b] = temp;
        a++;
        b--;
    }
}

/**
 * slide_zero - Moves non-zero elements forward, zeros to the back.
 * @line: Pointer to the array.
 * @size: Number of elements.
 * Description: Moves all non-zero elements to the front and pushes zeros back.
 */
void slide_zero(int *line, size_t size)
{
    size_t i = 0;
    size_t zero = 0; /* Count of zeros encountered */

    while (i < size)
    {
        if (line[i] == 0)
        {
            zero++;
        }
        else if (zero > 0)
        {
            line[i - zero] = line[i];
            line[i] = 0;
        }
        i++;
    }
}

/**
 * slide_non_zero - Merges adjacent equal non-zero elements.
 * @line: Pointer to the array.
 * @size: Number of elements.
 * Description: Merges elements that are the same and adjacent by doubling
 * the value of the left element and setting the right one to zero.
 */
void slide_non_zero(int *line, size_t size)
{
    for (size_t i = 0; i < size - 1; i++) /* Avoid out of bounds */
    {
        if (line[i] != 0 && line[i] == line[i + 1])
        {
            line[i] *= 2;
            line[i + 1] = 0;
            i++; /* Skip next element as it's merged */
        }
    }
}

/**
 * slide_line - Slides and merges an array of integers.
 * @line: Pointer to the array.
 * @size: Number of elements.
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT).
 * Return: 1 if success, 0 if failure.
 * Description: Applies operations to slide and merge integers in an array
 * according to 2048 game mechanics.
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction == SLIDE_LEFT)
    {
        slide_zero(line, size);
        slide_non_zero(line, size);
        slide_zero(line, size);
        return 1;
    }
    else if (direction == SLIDE_RIGHT)
    {
        reverse(line, size);
        slide_zero(line, size);
        slide_non_zero(line, size);
        slide_zero(line, size);
        reverse(line, size);
        return 1;
    }
    return 0; /* Invalid direction */
}
