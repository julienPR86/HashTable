#include "hashTableNode.h"
#include <stdio.h>
HTNode	*HTNode_max(HTNode *head)
{
	HTNode	*max = head;

	if (NULL == head)
		return (NULL);
	while (head)
	{
		if (head->value > max->value)
			max = head;
		head = head->next;
	}
	return (max);
}
