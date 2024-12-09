#include "regex.h"

/**
 * regex_match - Checks whether a given pattern matches a given string
 * @str: The string to scan
 * @pattern: The pattern to match
 *
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
if (!*pattern)
return (!*str);

int check_dot = *str && (*str == *pattern || *pattern == '.');

if (*(pattern + 1) == '*')
return (regex_match(str, pattern + 2) ||
(check_dot && regex_match(str + 1, pattern)));

if (check_dot)
return (regex_match(str + 1, pattern + 1));

return (0);
}

