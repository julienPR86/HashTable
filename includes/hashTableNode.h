#ifndef HASHTABLENODE_H
# define HASHTABLENODE_H

# include <stdlib.h>
# include <string.h>

typedef struct s_hashTableNode
{
	char					*key;
	size_t					value;
	struct s_hashTableNode	*next;
}	HTNode;

HTNode	*HTNode_new(const char *key, size_t value);

void	HTNode_destroy(HTNode **head);

HTNode	*HTNode_append(HTNode **head, const char *key, size_t value);

HTNode	*HTNode_get(const HTNode *head, const char *key);

HTNode	*HTNode_cpy(const HTNode *src);

#endif
