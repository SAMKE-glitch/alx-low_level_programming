#include "hash_tables.h"

/**
 * key_index - function that gives me the index of key named key
 * @key: the key the index from
 * @size: the size of an array
 *
 * Return: The index of the key
 *
 * Description: Uses the djb2 algorithm
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
