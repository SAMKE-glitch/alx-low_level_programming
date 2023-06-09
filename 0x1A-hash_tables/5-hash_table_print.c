#include "hash_tables.h"

/**
 * hash_table_print - Prints the hash table
 * @ht: Pointer to the hash table to be printed
 *
 * Description: Key/value pairs are printed in the order they appear
 *		in the array of the hash table.
 *
 * Return: Void
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i;
	unsigned char comma_flg = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (comma_flg == 1)
				printf(", ");

			node = ht->array[i];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
					printf(", ");
			}
			comma_flg = 1;
		}
	}
	printf("}\n");
}
