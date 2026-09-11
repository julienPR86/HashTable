#include "hashTableNode.h"

HTNode	*HTNode_get(const HTNode *head, const char *key)
{
	if (NULL == head)
		return (NULL);
	while (head)
	{
		if (0 == strcmp(head->key, key))
			break;
		head = head->next;
	}
	return ((HTNode *)head);
}
