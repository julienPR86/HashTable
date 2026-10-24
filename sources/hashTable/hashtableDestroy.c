#include "hashTable.h"

void	hashtableDestroy(t_hashtable *table)
{
	if (NULL == table)
		return ;
	if (NULL != table->data)
	{
		for (size_t i = 0; i < table->capacity; ++i)
		{
			if (NULL == *(table->data + i))
				continue;
			llistDestroy(table->data + i, (t_llistDestroyFn)&HTEntryDestroy);
		}
		free(table->data);
		table->data = NULL;
	}
	free(table);
	return ;
}
