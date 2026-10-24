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
			t_llist	*cur = *(table->data + index);
			while (cur)
			{
				if (cur->data)
					printf("%s: %zu\n", ((t_HTEntry *)cur->data)->key, ((t_HTEntry *)cur->data)->value);
				cur = cur->next;
			}
		}
		++index;
	}
	return ;
}
