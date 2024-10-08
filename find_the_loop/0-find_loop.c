#include "lists.h"
#include <stdio.h>
/**
 * find_listint_loop - Find the beginning of a loop in a linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Return: If there is no loop, return NULL. Otherwise, return a pointer
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hare, *tortoise;

	if (!head)
		return (NULL);

	hare = tortoise = head;

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = (hare->next)->next;

		if (hare == tortoise)
		{
			tortoise = head;

			while (tortoise && hare)
			{
				if (tortoise == hare)
					return (tortoise);

				tortoise = tortoise->next;
				hare = hare->next;
			}
		}
	}

	return (NULL);
}
