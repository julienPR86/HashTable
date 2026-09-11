#include "hashTable.h"

HTNode	*HashTable_first(HashTable *table)
{
	size_t	index = 0;

	if (NULL == table || NULL == table->data)
		return (NULL);
	while (index < table->capacity)
	{
		if (NULL != *(table->data + index))
			break;
		++index;
	}
	return (*(table->data + index));
}
