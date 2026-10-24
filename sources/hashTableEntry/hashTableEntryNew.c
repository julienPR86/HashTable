#include "hashTableEntry.h"

t_HTEntry	*HTEntryNew(const char *key, size_t val)
{
	t_HTEntry	*new;

	new = malloc(sizeof(t_HTEntry));
	if (NULL == new)
		return (NULL);
	new->key = strDup(key);
	if (NULL == new->key)
	{
		free(new);
		return (NULL);
	}
	new->value = val;
	return (new);
}
