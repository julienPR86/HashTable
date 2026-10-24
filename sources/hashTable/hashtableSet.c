#include "hashTable.h"
#include "hash.h"

t_hashtable	*hashtableSet(t_hashtable *table, const char *key, const size_t value)
{
	size_t		hashv;
	t_HTEntry	*entry;

	if (NULL == table || NULL == key)
		return (NULL);
	hashv = hash(key);
	entry = HTEntryNew(key, value);
	if (NULL == entry)
		return (NULL);
	if (hashv >= table->capacity)
	{
		//TODO: save a copy of data in case realloc fails
		table->data = realloc(table->data, (hashv + 1) * sizeof(t_llist *));
		if (NULL == table->data)
		{
			free(entry);
			return (NULL);
		}
		strMemSet(table->data + table->capacity, 0, (hashv + 1 - table->capacity) * sizeof(t_llist *));
		table->bsize = (hashv + 1) * sizeof(t_llist *);
		table->capacity = hashv + 1;
		if (NULL == llistPushBack(table->data + hashv, llistNew(entry)))
		{
			free(entry);
			return (NULL);
		}
		return (table);
	}

	if (NULL == *(table->data + hashv))
	{
		*(table->data + hashv) = llistNew(entry);
		if (NULL == *(table->data + hashv))
		{
			free(entry);
			return (NULL);
		}
		return (table);
	}

	t_llist	*node = llistGetFor(*(table->data + hashv), (t_llistCompareFn)&HTEntryCompareKeys, key);
	if (NULL == node)
	{
		if (NULL == llistPushBack(table->data + hashv, llistNew(entry)))
		{
			free(entry);
			return (NULL);
		}
		return (table);
	}
	((t_HTEntry *)node->data)->value = value;
	return (table);
}
