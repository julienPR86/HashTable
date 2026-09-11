#include "hashTableNode.h"

void	HTNode_destroy(HTNode **head)
{
	HTNode	*next;

	if (NULL == head || NULL == *head)
		return ;
	while (*head)
	{
		next = (*head)->next;
		free((*head)->key);
		(*head)->key = NULL;
		// free((*head)->value);
		// (*head)->value = NULL;
		free(*head);
		*head = next;
	}
	return ;
}
