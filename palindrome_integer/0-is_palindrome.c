#include <stdio.h>
#include "palindrome.h"
/*
* is_palindrome - function that checks whether or not a given unsigned integer is a palindrome.
* @n: is the number to be checked
*
* Return: 1 if n is a palindrome, and 0 otherwise
*/
int is_palindrome(unsigned long n)
{
    unsigned long original = n;
    unsigned long reversed = 0;

    while (n > 0)
    {
        unsigned long digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return (original == reversed) ? 1 : 0;
}