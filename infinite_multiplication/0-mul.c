#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * _isnumber - checks if a string is a number
 * @s: string to check
 * Return: 1 if the string is a number, 0 otherwise
 */
int _isnumber(char *s)
{
    int i;

    for (i = 0; s[i]; i++)
    {
        if (!isdigit(s[i]))
            return (0);
    }
    return (1);
}

/**
 * _callocX - allocates memory and initializes it to '0'
 * @nmemb: number of bytes to allocate
 * Return: pointer to the allocated memory
 */
char *_callocX(unsigned int nmemb)
{
    char *p;
    unsigned int i;

    p = malloc(nmemb + 1);
    if (p == NULL)
        return (NULL);
    
    for (i = 0; i < nmemb; i++)
        p[i] = '0';
    p[i] = '\0';  // Null-terminate the string
    return (p);
}

/**
 * main - multiplies two large positive numbers
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
    int i, j, l1, l2, lful, mul, add, ten, ten2, tl, zer = 0;
    char *res;

    if (argc != 3 || !_isnumber(argv[1]) || !_isnumber(argv[2]))
    {
        printf("Error\n");
        exit(98);
    }

    // Check if either number is zero
    if (strcmp(argv[1], "0") == 0 || strcmp(argv[2], "0") == 0)
    {
        printf("0\n");
        return (0);
    }

    l1 = strlen(argv[1]);
    l2 = strlen(argv[2]);
    lful = l1 + l2;

    res = _callocX(lful);
    if (res == NULL)
    {
        printf("Error\n");
        exit(98);
    }

    for (i = l2 - 1; i >= 0; i--)
    {
        ten = 0;
        ten2 = 0;
        for (j = l1 - 1; j >= 0; j--)
        {
            tl = i + j + 1;
            mul = (argv[1][j] - '0') * (argv[2][i] - '0') + ten;
            ten = mul / 10;
            add = (res[tl] - '
