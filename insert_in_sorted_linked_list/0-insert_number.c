#include "lists.h"
#include <stdlib.h>
/**
 * *insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to the head of linked list
 * @number: Number to be added
 * Return: the address of the new node, or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{

	listint_t *node, *current;


	node = malloc(sizeof(listint_t));
	node->n = number;
	if (*head == NULL)
	{
	*head = node;
		return (*head);
	}
	current = *head;
	if (node->n < current->n)
	{
		node->next = *head;
		*head = node;
	}
	else
	{
		current = *head;
		while (current->next != NULL && current->next->n < node->n)
			current = current->next;
		node->next = current->next;
		current->next = node;
	}
	return (node);
}
