#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _isnumber - checks if a string is a valid number
 * @s: the string to check
 * Return: 1 if valid, 0 otherwise
 */
int _isnumber(char *s)
{
    while (*s)
    {
        if (*s < '0' || *s > '9')
            return (0);
        s++;
    }
    return (1);
}

/**
 * _callocX - allocates memory initialized to '0'
 * @nmemb: number of bytes to allocate
 * Return: pointer to the allocated memory
 */
char *_callocX(unsigned int nmemb)
{
    char *p;
    unsigned int i;

    p = malloc(nmemb);
    if (!p)
        return (NULL);
    for (i = 0; i < nmemb; i++)
        p[i] = '0';
    return (p);
}

/**
 * multiply - multiplies two large numbers as strings
 * @num1: first number
 * @num2: second number
 */
void multiply(char *num1, char *num2)
{
    int len1 = 0, len2 = 0, i, j, carry, product;
	
    char *result;

    while (num1[len1])
        len1++;
    while (num2[len2])
        len2++;

    result = _callocX(len1 + len2);
    if (!result)
    {
        printf("Error\n");
        exit(98);
    }

    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            product = (num1[i] - '0') * (num2[j] - '0') + carry + (result[i + j + 1] - '0');
            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i + j + 1] += carry;
    }

    i = 0;
    while (result[i] == '0' && result[i + 1])
        i++;

    while (result[i])
    {
        _putchar(result[i]);
        i++;
    }
    _putchar('\n');
    free(result);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
    if (argc != 3 || !_isnumber(argv[1]) || !_isnumber(argv[2]))
    {
        printf("Error\n");
        exit(98);
    }

    multiply(argv[1], argv[2]);

    return (0);
}
