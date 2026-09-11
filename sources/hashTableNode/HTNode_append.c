#include "hashTableNode.h"

HTNode	*HTNode_append(HTNode **head, const char *key, size_t value)
{
	HTNode	*cpy;

	if (NULL == head || NULL == key)
		return (NULL);
	if (NULL == *head)
	{
		*head = HTNode_new(key, value);
		if (NULL == *head)
			return (NULL);
		return (*head);
	}
	cpy = *head;
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = HTNode_new(key, value);
	if (NULL == cpy->next)
		return (NULL);
	return (*head);
}
