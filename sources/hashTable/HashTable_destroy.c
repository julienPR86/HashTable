#include "hashTable.h"

void	HashTable_destroy(HashTable *table)
{
	if (NULL == table)
		return ;
	if (NULL != table->data)
		HashTable_destroy_data(table);
	free(table);
	return ;
}

void	HashTable_destroy_data(HashTable *table)
{
	if (NULL == table || NULL == table->data)
		return ;
	for (size_t i = 0; i < table->capacity; ++i)
	{
		if (NULL == *(table->data + i))
			continue;
		HTNode_destroy(table->data + i);
	}
	free(table->data);
	table->data = NULL;
	return ;
}
