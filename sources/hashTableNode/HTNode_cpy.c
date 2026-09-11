#include "hashTableNode.h"

HTNode	*HTNode_cpy(const HTNode *src)
{
	HTNode	*head;
	HTNode	*cpy;

	if (NULL == src)
		return (NULL);
	head = HTNode_new(src->key, src->value);
	if (NULL == head)
		return (NULL);
	cpy = head;
	while (src->next)
	{
		cpy->next = HTNode_new(src->next->key, src->next->value);
		if (NULL == cpy->next)
		{
			HTNode_destroy(&head);
			return (NULL);
		}
		src = src->next;
	}
	return (head);
}
