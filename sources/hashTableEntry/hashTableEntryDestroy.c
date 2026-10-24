#include "hashTableEntry.h"

void	HTEntryDestroy(t_HTEntry *entry)
{
	if (NULL == entry)
		return ;
	free(entry->key);
	// free(entry->value);
	free(entry);
	return ;
}
