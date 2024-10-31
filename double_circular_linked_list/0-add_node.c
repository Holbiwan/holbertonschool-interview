#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 *
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node;
	char *str_copy;

	if (!list)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	str_copy = strdup(str);
	if (!str_copy)
	{
		free(new_node);
		return (NULL);
	}
	new_node->str = str_copy;

	if (!*list)
	{
		/* If the list is empty, initialize the first node to point to itself */
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		/* Insert the new node at the end of the list */
		new_node->next = *list;
		new_node->prev = (*list)->prev;

		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
	}

	return (new_node);
}

/**
 * add_node_begin - Adds a new node at double circular linked list start
 *
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;
	char *str_copy;

	if (!list)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	str_copy = strdup(str);
	if (!str_copy)
	{
		free(new_node);
		return (NULL);
	}
	new_node->str = str_copy;

	if (!*list)
	{
		/* If the list is empty, initialize the new node to point to itself */
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		/* Insert the new node at the beginning of the list */
		new_node->next = *list;
		new_node->prev = (*list)->prev;

		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
	}

	*list = new_node; /* Update the head to the new node */

	return (new_node);
}
