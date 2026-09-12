#include "hashTableNode.h"

HTNode	*HTNode_new(const char *key, size_t value)
{
	HTNode	*new;

	if (NULL == key)
		return (NULL);
	new = malloc(sizeof(HTNode));
	if (NULL == new)
		return (NULL);
	new->key = strDup(key);
	if (NULL == new->key)
	{
		free(new);
		return (NULL);
	}
	new->value = value;
	new->next = NULL;
	return (new);
}
