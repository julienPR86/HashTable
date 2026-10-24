#include "hashTable.h"

t_hashtable	*hashtableNew(size_t initial_capacity)
{
	t_hashtable	*new;

	new = malloc(sizeof(t_hashtable));
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
