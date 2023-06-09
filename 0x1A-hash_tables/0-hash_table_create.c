#include "hash_tables.h"

/**
 * hash_table_create - a function pointer that creates a hash table
 * @size: The size of the array in this case hash table
 *
 * Return: If on errors then NULL, or a pointer to the new hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table_created;
	unsigned long int i;

	table_created = malloc(sizeof(hash_table_t));

	if (table_created == NULL)
		return (NULL);

	table_created->size = size;
	table_created->array = malloc(sizeof(hash_node_t *) * size);
	if (table_created->array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		table_created->array[i] = NULL;
	}

	return (table_created);
}
