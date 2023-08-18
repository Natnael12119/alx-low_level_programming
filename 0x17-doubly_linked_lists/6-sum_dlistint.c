#include "lists.h"

/**
 * sum_dlistint - Calculates the sum of all the data in a doubly linked list.
 *
 * @head: The head of the list.
 *
 * Return: The sum of all the data.
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
