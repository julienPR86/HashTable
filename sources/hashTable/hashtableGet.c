#include "hashTable.h"
#include "hash.h"

t_HTEntry	*hashtableGet(const t_hashtable *table, const char *key)
{
	size_t	hashv;
	t_llist	*node;

	if (NULL == table || NULL == key)
		return (NULL);
	hashv = hash(key);
	if (hashv >= table->capacity)
		return (NULL);
	node = llistGetFor(*(table->data + hashv), (t_llistCompareFn)&HTEntryCompareKeys, key);
	if (NULL == node)
		return (NULL);
	return (node->data);
}
