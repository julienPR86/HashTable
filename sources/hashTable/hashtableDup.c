#include "hashTable.h"

t_hashtable	*hashtableDup(const t_hashtable *src)
{
	size_t		index = 0;
	t_hashtable	*cpy;

	if (NULL == src)
		return (NULL);
	cpy = hashtableNew(src->capacity);
	if (NULL == cpy)
		return (NULL);
	while (index < src->capacity)
	{
		if (NULL != *(src->data + index))
		{
			*(cpy->data + index) = llistDup(*(src->data + index), (t_llistDupFn)&HTEntryDup, (t_llistDestroyFn)&HTEntryDestroy);
			if (NULL == *(cpy->data + index))
			{
				hashtableDestroy(cpy);
				return (NULL);
			}
		}
		++index;
	}
	return (cpy);
}
