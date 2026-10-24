#include "hashTable.h"

HashTable	*HashTable_new(size_t initial_capacity)
{
	HashTable	*new;

	new = malloc(sizeof(HashTable));
	if (NULL == new)
		return (NULL);
	new->bsize = initial_capacity * sizeof(t_HTEntry *);
	new->capacity = initial_capacity;
	new->data = calloc(1, new->bsize);
	if (NULL == new->data)
	{
		free(new);
		return (NULL);
	}
	return (new);
}
