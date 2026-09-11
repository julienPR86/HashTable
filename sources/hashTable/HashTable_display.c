#include "hashTable.h"

void	HashTable_display(HashTable *table)
{
	size_t	index = 0;

	if (NULL == table || NULL == table->data)
		return ;
	while (index < table->capacity)
	{
		if (*(table->data + index))
		{
			HTNode	*cur = *(table->data + index);
			while (cur)
			{
				printf("%s: %zu\n", cur->key, cur->value);
				cur = cur->next;
			}
		}
		++index;
	}
	return ;
}
