#include "hashTable.h"

t_hashtable	*HashTable_dup(const t_hashtable *src)
{
	size_t		index = 0;
	t_hashtable	*cpy;

	if (NULL == src)
		return (NULL);
	cpy = HashTable_new(src->capacity);
	if (NULL == cpy)
		return (NULL);
	while (index < src->capacity)
	{
		if (NULL != *(src->data + index))
		{
			*(cpy->data + index) = llistDup(*(src->data + index), (t_llistDupFn)&HTEntryDup, (t_llistDestroyFn)&HTEntryDestroy);
			if (NULL == *(cpy->data + index))
			{
				HashTable_destroy(cpy);
				return (NULL);
			}
		}
		++index;
	}
	return (cpy);
}
