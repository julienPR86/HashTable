#include "hashTable.h"

t_HTEntry	*hashtableFirst(t_hashtable *table)
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
	return (((t_llist *)*(table->data + index))->data);
}
