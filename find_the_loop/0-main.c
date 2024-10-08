#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * create_list - Creates a linked list with the specified elements.
 * @head: Double pointer to the head of the list.
 */
void create_list(listint_t **head)
{
	add_nodeint(head, 0);
	add_nodeint(head, 1);
	add_nodeint(head, 2);
	add_nodeint(head, 3);
	add_nodeint(head, 4);
	add_nodeint(head, 98);
	add_nodeint(head, 402);
	add_nodeint(head, 1024);
}

/**
 * check_loop - Checks if there is a loop in the linked list.
 * @head: Pointer to the head of the list.
 */
void check_loop(listint_t *head)
{
	listint_t *node;

	node = find_listint_loop(head);
	if (node != NULL)
	{
		printf("Loop starts at [%p] %d\n", (void *)node, node->n);
	}
}

/**
 * main - Tests the creation of a linked list and checks for a loop.
 *
 * Return: Always 0.
 */
int main(void)
{
	listint_t *head;
	listint_t *head2;
	listint_t *node;

	head2 = NULL;
	create_list(&head2);
	print_listint_safe(head2);
	check_loop(head2);
	free_listint_safe(&head2);

	head = NULL;
	node = add_nodeint(&head, 0);
	add_nodeint(&head, 1);
	add_nodeint(&head, 2);
	add_nodeint(&head, 3);
	add_nodeint(&head, 4);
	add_nodeint(&head, 5);
	add_nodeint(&head, 6);
	node->next = add_nodeint(&head, 7);
	add_nodeint(&head, 98);
	add_nodeint(&head, 402);
	add_nodeint(&head, 1024);
	print_listint_safe(head);
	check_loop(head);
	free_listint_safe(&head);

	return (0);
}
