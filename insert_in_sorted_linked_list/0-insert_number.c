#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 *
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    if (!new_node)
        return NULL;

    new_node->n = number;
    new_node->next = NULL;

    if (!*head || (*head)->n >= new_node->n)
    {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    listint_t *current = *head;
    while (current->next && current->next->n < new_node->n)
        current = current->next;

    new_node->next = current->next;
    current->next = new_node;

    return new_node;
}
