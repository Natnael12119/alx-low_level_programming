#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node to the end of a doubly linked list.
 *
 * @head: The head of the list.
 * @n: The data to store in the new node.
 *
 * Return: The address of the new node, or NULL if the function fails.
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *last;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;

	return (new);
}
