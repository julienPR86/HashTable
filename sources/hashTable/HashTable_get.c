#include "hashTable.h"
#include "hash.h"

HTNode	*HashTable_get(const HashTable *table, const char *key)
{
	size_t	hashv;

	if (NULL == table || NULL == key)
		return (NULL);
	hashv = hash(key);
	if (hashv >= table->capacity)
		return (NULL);
	return (HTNode_get(*(table->data + hashv), key));
}
