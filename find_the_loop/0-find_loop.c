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
    listint_t *slow = head;
    listint_t *fast = head;

    if (!head)
        return (NULL);

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return (fast);
        }
    }
    return (NULL);
}
