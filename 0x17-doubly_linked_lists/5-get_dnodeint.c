#include "lists.h"

/**
 * get_dnodeint_at_index - function that returns nth node of a linked list
 * @head: pointer to the list head
 * @index: the node we shall access is in index
 *
 * Return: doubly linked list
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	if (head == NULL)
		return (NULL);

	while (head->prev != NULL)
		head = head->prev;

	i = 0;

	while (head != NULL)
	{
		if (i == index)
			break;
		head = head->next;
		i++;
	}
	return (head);
}
