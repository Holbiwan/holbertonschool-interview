#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * menger - Function that draws a 2D Menger Sponge
 * @level:  Level of the Menger Sponge to draw
 * Return: void
 */
void menger(int level)
{
    int x, y, size;

    if (level < 0)
        return;

    size = pow(3, level);
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            printf("%c", printer(x, y));
        }
        printf("\n");
    }
}

/**
 * printer - Checks whether a "#" or a " "
 * corresponds to each coordinate point
 * @x: X coordinate (row)
 * @y: Y coordinate (column)
 * Return: '#' or ' '
 */
static char printer(int x, int y)
{
    while (x > 0 || y > 0)
    {
        if (x % 3 == 1 && y % 3 == 1)
            return ' ';
        x /= 3;
        y /= 3;
    }
    return '#';
}
