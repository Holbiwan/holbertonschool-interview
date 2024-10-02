#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * _isnumber - checks if string is a number
 * @s: string to check
 * Return: 1 if the string is a number, 0 otherwise
 */
int _isnumber(char *s)
{
    for (int i = 0; s[i]; i++)
        if (!isdigit(s[i]))
            return (0);
    return (1);
}

/**
 * _callocX - allocates memory and initializes it to '0'
 * @nmemb: number of elements
 * Return: pointer to allocated memory, NULL on failure
 */
char *_callocX(unsigned int nmemb)
{
    char *p = malloc(nmemb + 1); // +1 for null terminator
    if (!p)
        return (NULL);
    for (unsigned int i = 0; i < nmemb; i++)
        p[i] = '0';
    p[nmemb] = '\0'; // Null-terminate the string
    return (p);
}

/**
 * multiply - multiplies two numbers represented as strings
 * @num1: first number
 * @num2: second number
 */
void multiply(char *num1, char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len_res = len1 + len2;
    char *res = _callocX(len_res);  // Allocate result array of len1 + len2

    if (!res)
        exit(98);

    // Multiply digits one by one
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = len2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0') + (res[i + j + 1] - '0') + carry;
            carry = product / 10;
            res[i + j + 1] = (product % 10) + '0';  // Store result in correct position
        }
        res[i + len2] += carry;  // Add remaining carry to the next left position
    }

    // Skip leading zeros
    int start = 0;
    while (start < len_res && res[start] == '0')
        start++;

    // Print result, or "0" if all digits are zero
    if (start == len_res)
        printf("0\n");
    else
        printf("%s\n", res + start);

    free(res);
}

int main(int argc, char **argv)
{
    if (argc != 3 || !_isnumber(argv[1]) || !_isnumber(argv[2])) {
        printf("Error\n");
        return (98);
    }
    multiply(argv[1], argv[2]);
    return (0);
}
