#include "lists.h"

/**
 * get_dnodeint_at_index - Locates a node in a doubly linked list.
 *
 * @head: The head of the list.
 * @index: The index of the node to locate.
 *
 * Return: The address of the located node, or NULL if the node does not exist.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	for (; index != 0; index--)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}

	return (head);
}
