#include "hashTable.h"

HashTable	*HashTable_dup(const HashTable *src)
{
	size_t	index = 0;
	HashTable	*cpy;

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
