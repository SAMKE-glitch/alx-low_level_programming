#include "lists.h"

/**
 * delete_dnodeint_at_index - function that deletes a node at index
 * @head: pointer head to the linked list
 * @index: the index to delete ouir node int eh doubly list
 *
 * Return: integer
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *ptr1;
	dlistint_t *ptr2;
	unsigned int i;

	ptr1 = *head;

	if (ptr1 != NULL)
		while (ptr1->prev != NULL)
			ptr1 = ptr1->prev;

	i = 0;

	while (ptr1 != NULL)
	{
		if (i == index)
		{
			if (i == 0)
			{
				*head = ptr1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				ptr2->next = ptr1->next;

				if (ptr1->next != NULL)
					ptr1->next->prev = ptr2;
			}
			free(ptr1);
			return (1);
		}
		ptr2 = ptr1;
		ptr1 = ptr1->next;
		i++;
	}
	return (-1);
}
