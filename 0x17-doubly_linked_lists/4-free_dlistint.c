#include "lists.h"

/**
 * free_dlistint - function that frees a doubly linked list
 * @head: pointer to the list
 *
 * Return: nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	if (head != NULL)
		while (head->prev != NULL)
			head = head->next;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
