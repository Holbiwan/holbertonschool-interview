#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "substring.h"

/**
 * _strlen - Find length of a string
 * @s: String to get length of
 * Return: Length of the string
 */
int _strlen(const char *s)
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
int _strncmp(const char *s1, const char *s2, int n)
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
 * reset_wordused - Reset the wordused array to 0
 * @wordused: Array to reset
 * @nb_words: Number of words
 */
void reset_wordused(int *wordused, int nb_words)
{
	int i;

	for (i = 0; i < nb_words; i++)
		wordused[i] = 0;
}

/**
 * match_words - Match words in the substring of s
 * @s: Substring to search
 * @words: Array of words to match
 * @wordused: Array to track used words
 * @nb_words: Number of words
 * @wordlen: Length of each word
 * Return: 1 if all words match, 0 otherwise
 */
int match_words(const char *s, const char **words, int *wordused,
		      int nb_words, int wordlen)
{
	int i, j, matched, wordcount = nb_words;

	for (i = 0; i < nb_words; i++)
		wordused[i] = 0;

	while (wordcount > 0)
	{
		matched = 0;
		for (j = 0; j < nb_words; j++)
		{
			if (!wordused[j] && !_strncmp(s, words[j], wordlen))
			{
				wordused[j] = 1;
				s += wordlen;
				wordcount--;
				matched = 1;
				break;
			}
		}
		if (!matched)
			return (0);
	}
	return (1);
}

/**
 * find_substring - Finds starting indices of substrings done by concatenation
 *                  of a list of words in any order exactly once each.
 * @s: String to search
 * @words: array of words to look for into
 * @nb_words: Number of words in the array
 * @n: Variable to return number of indices found
 * Return: NULL on failure, or array of indices substring is found at
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
	int *found, *wordused;
	int len, wordlen, i;

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

	*n = 0;
	for (i = 0; i <= len - wordlen * nb_words; i++)
	{
		if (match_words(s + i, words, wordused, nb_words, wordlen))
		{
			found[*n] = i;
			(*n)++;
		}
	}

	free(wordused);
	if (*n == 0)
	{
		free(found);
		return (NULL);
	}
	return (found);
}
