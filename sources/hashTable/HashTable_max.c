#include "hashTable.h"

HTNode	*HashTable_max(HashTable *table)
{
	size_t	index = 0;
	HTNode	*max;

	if (NULL == table || NULL == table->data)
		return (NULL);
	max = HashTable_first(table);
	while (index < table->capacity)
	{
		if (*(table->data + index))
		{
			HTNode	*tmp = HTNode_max(*(table->data + index));
			if (tmp && tmp->value > max->value)
				max = tmp;
		}
		++index;
	}
	return (max);
}
