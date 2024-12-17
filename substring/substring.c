#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "substring.h"

/**
 * _strlen - Find length of a string
 * @s: String to get length of
 * Return: Length of the string
 */
int _strlen(char const *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strncmp - Compare two strings up to n characters
 * @s1: First string
 * @s2: Second string
 * @n: Maximum compare length
 * Return: 0 if the same, 1 otherwise
 */
int _strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0' || s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * find_substring - Finds starting indices of substrings formed by concatenation
 *                  of a list of words in any order exactly once each.
 * @s: String to search
 * @words: Array of words to look for into
 * @nb_words: Number of words in the array
 * @n: Variable to return number of indices found
 * Return: NULL on failure, or array of indices substring is found at
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *found, *wordused;
	int len, i, j, k, wordcount, wordlen;

	if (nb_words == 0 || n == NULL || s == NULL || words == NULL)
		return (NULL);

	wordlen = _strlen(words[0]);
	len = _strlen(s);

	found = malloc(len * sizeof(int));
	if (!found)
		return (NULL);

	wordused = malloc(nb_words * sizeof(int));
	if (!wordused)
	{
		free(found);
		return (NULL);
	}

	*n = 0; /* Initialize number of matches found */

	/* Iterate over the main string */
	for (i = 0; i <= len - wordlen * nb_words; i++)
	{
		for (k = 0; k < nb_words; k++)
			wordused[k] = 0;

		wordcount = nb_words;
		k = i;

		/* Check if substring matches all words in any order */
		while (wordcount > 0)
		{
			int matched = 0;

			for (j = 0; j < nb_words; j++)
			{
				if (!wordused[j] && !_strncmp(s + k, words[j], wordlen))
				{
					wordused[j] = 1;
					wordcount--;
					k += wordlen;
					matched = 1;
					break;
				}
			}

			if (!matched) /* No match found for the current segment */
				break;
		}

		if (wordcount == 0) /* All words matched */
		{
			found[*n] = i;
			(*n)++;
		}
	}

	free(wordused);

	if (*n == 0) /* No matches found */
	{
		free(found);
		return (NULL);
	}

	return (found);
}
