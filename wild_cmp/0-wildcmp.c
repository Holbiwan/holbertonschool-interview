#include "holberton.h"

/**
 * wildcmp - compares two strings and returns 1 if the strings
 * can be considered identical, otherwise return 0.
 * @s1: string to compare to
 * @s2: string with wildcard character
 *
 * Return: 1 if the strings can be considered identical,
 * otherwise return 0.
 */
int wildcmp(char *s1, char *s2)
{
    // If both strings are empty, they are identical.
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    // If the characters match, move to the next characters in both strings.
    if (*s1 == *s2)
        return (wildcmp(s1 + 1, s2 + 1));

    // If `*` is encountered in s2.
    if (*s2 == '*')
    {
        // Consider `*` as an empty string OR match it with a character in s1.
        return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
    }

    // Otherwise, the strings are not identical.
    return (0);
}
