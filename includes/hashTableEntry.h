#ifndef HASHTABLEENTRY_H
# define HASHTABLEENTRY_H

# include <stdlib.h>
# include <stdbool.h>
# include "libstr.h"

typedef struct s_hashTableEntry
{
	char	*key;
	size_t	value;
}	t_HTEntry;

t_HTEntry	*HTEntryNew(const char *key, size_t val);

t_HTEntry	*HTEntryDup(const t_HTEntry *src);

int	HTEntryCompareKeys(const char *entry1, const char *entry2);

void	HTEntryDestroy(t_HTEntry *entry);

#endif
