#include "hashTable.h"

HashTable	*HashTable_cpy(const HashTable *src)
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
			*(cpy->data + index) = HTNode_cpy(*(src->data + index));
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
