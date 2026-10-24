#include "hashTableEntry.h"

t_HTEntry	*HTEntryDup(const t_HTEntry *src)
{
	t_HTEntry	*dup;

	dup = HTEntryNew(src->key, src->value);
	if (NULL == dup)
		return (NULL);
	return (dup);
}
