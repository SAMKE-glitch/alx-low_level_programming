#include "lists.h"

/**
 * dlistint_len - function that returns number of elements in a list
 * @h: head pointer pointing to the 1st node
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	int count;

	count = 0;

	if (h == NULL)
		return (count);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
