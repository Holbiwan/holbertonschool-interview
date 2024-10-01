#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * _isnumber - Checks if a string is composed only of digits
 * @s: The string to check
 *
 * Return: 1 if the string is a number, 0 otherwise
 */
int _isnumber(char *s)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i])) // Use isdigit() to check if each character is a digit
            return (0);
    }
    return (1);
}

/**
 * _callocX - Allocates memory and initializes it to '0'
 * @nmemb: Number of bytes to allocate
 *
 * Return: Pointer to the allocated memory, or NULL if allocation fails
 */
char *_callocX(unsigned int nmemb)
{
    unsigned int i;
    char *p;

    p = malloc(nmemb + 1); // Allocate memory for the number of bytes plus a null terminator
    if (p == NULL)
        return (NULL);
    for (i = 0; i < nmemb; i++)
        p[i] = '0'; // Initialize all bytes to '0'
    p[i] = '\0'; // Add the null terminator at the end
    return (p);
}

/**
 * main - Multiplies two large positive numbers passed as command-line arguments
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
    int i, j, l1, l2, lful, mul, add, carry1, carry2, tl, zer = 0;
    char *res;

    // Check if the number of arguments is correct and if both arguments are valid numbers
    if (argc != 3 || _isnumber(argv[1]) == 0 || _isnumber(argv[2]) == 0)
    {
        printf("Error\n");
        exit(98);
    }

    // If either number is zero, print '0' and exit
    if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
    {
        printf("0\n");
        return (0);
    }

    // Get the lengths of both numbers
    l1 = strlen(argv[1]);
    l2 = strlen(argv[2]);
    lful = l1 + l2; // The length of the result will be at most l1 + l2

    // Allocate memory for the result and initialize it to '0'
    res = _callocX(lful);
    if (res == NULL)
    {
        printf("Error\n");
        exit(98);
    }

    // Multiply the numbers digit by digit from the end
    for (i = l2 - 1; i >= 0; i--)
    {
        carry1 = 0; // carry1 handles the carry from multiplication
        carry2 = 0; // carry2 handles the carry from addition to result array
        for (j = l1 - 1; j >= 0; j--)
        {
            tl = i + j + 1; // Position in result where current multiplication will go
            mul = (argv[1][j] - '0') * (argv[2][i] - '0') + carry1;
            carry1 = mul / 10; // Update carry from multiplication
            add = (res[tl] - '0') + (mul % 10) + carry2;
            carry2 = add / 10; // Update carry from addition
            res[tl] = (add % 10) + '0'; // Store result digit
        }
        res[tl - 1] = (carry1 + carry2) + '0'; // Handle the remaining carry
    }

    // Remove leading zeros from the result
    if (res[0] == '0')
        zer = 1; // Skip leading zeros

    // Print the result
    for (; zer < lful; zer++)
        printf("%c", res[zer]);
    printf("\n");

    // Free the allocated memory
    free(res);

    return (0);
}
