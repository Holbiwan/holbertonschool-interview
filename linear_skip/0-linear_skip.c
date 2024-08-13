#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express = list;
	skiplist_t *prev = list;

	if (!list)
		return (NULL);

	while (express)
	{
		prev = express;
		express = express->express;
		printf("Value checked at index [%lu] = [%d]\n",
			express->index, express->n);
		if (express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				prev->index, express->index);
			break;
		}
		if (!express->express)
		{
			prev = express;
			while (express->next)
				express = express->next;
			printf("Value found between indexes [%lu] and [%lu]\n",
				prev->index, express->index);
			break;
		}
	}
	while (prev)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		if (prev->n > value)
			break;
		prev = prev->next;
	}
	return (NULL);
}
