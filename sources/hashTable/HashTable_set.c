#include "hashTable.h"
#include "hash.h"

HashTable	*HashTable_set(HashTable *table, const char *key, const size_t value)
{
	size_t	hashv;

	if (NULL == table || NULL == key)
		return (NULL);
	hashv = hash(key);
	if (hashv >= table->capacity)
	{
		size_t	index = 0;
		HashTable	*new = HashTable_new(hashv + 1);

		if (NULL == new)
			return (NULL);
		while (index < table->capacity)
		{
			if (NULL != *(table->data + index))
			{
				*(new->data + index) = HTNode_cpy(*(table->data + index));
				if (NULL == *(new->data + index))
				{
					HashTable_destroy(new);
					return (NULL);
				}
			}
			++index;
		}
		HashTable_destroy_data(table);
		table->data = new->data;
		table->bsize = new->bsize;
		table->capacity = new->capacity;
		if (NULL == HTNode_append(table->data + hashv, key, value))
			return (NULL);
		free(new);
		return (table);
	}
	if (NULL == *(table->data + hashv))
	{
		*(table->data + hashv) = HTNode_new(key, value);
		if (NULL == *(table->data + hashv))
			return (NULL);
	}

	HTNode	*node = HTNode_get(*(table->data + hashv), key);
	if (NULL == node)
	{
		if (NULL == HTNode_append(table->data + hashv, key, value))
			return (NULL);
		return (table);
	}
	node->value = value;
	return (table);
}
