#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - insert node
 * @head: list root
 * @number: giving number for new node
 *
 * Return: new_node if success, NULL if fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *curr, *prev;

	new_node = (listint_t *) malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
		return (new_node);
	}
	curr = *head;
	prev = NULL;
	while (curr != NULL)
	{
		if (curr->n < number)
		{
			prev = curr;
			curr = curr->next;
		}
		else
			break;
	}
	if (prev == NULL)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	prev->next = new_node;
	new_node->next = curr;
	return (new_node);
}
