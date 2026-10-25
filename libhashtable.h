#ifndef LIBHASHTABLE_H
# define LIBHASHTABLE_H

# include <stdlib.h>

# ifdef LIBHASHTABLE_IMPLEMENTATION
#  ifndef LIBLLIST_IMPLEMENTATION
#   define LIBLLIST_IMPLEMENTATION
#  endif
# endif
# include "libs/libllist/libllist.h"

# define HASHTABLE_PRIVATE(name) name##_private

typedef struct s_hashTableEntry
{
	char	*key;
	size_t	value;
}	t_hashtableEntry;

typedef struct s_hashTable
{
	/**
	 * @brief The size of data in bytes
	 */
	size_t	bsize;
	/**
	 * @brief The number of entries that can be stored
	 */
	size_t	capacity;
	/**
	 * @brief Pointer to the data array
	 * @warning It is not NULL terminated !
	 */
	t_llist	**data;
}	t_hashtable;

/**
 * @brief Creates a new hashTableHash table.
 * @param initial_capacity The initial number of entries the table can store.
 * @return A pointer to the newly created hashTableHash table.
 */
t_hashtable	*hashtableNew(size_t initial_capacity);

/**
 * @brief Stores data inside the table if key is inexistent, updates it otherwise.
 * @return The updated hashTableHash table.
 */
t_hashtable	*hashtableSet(t_hashtable *table, const char *key, const size_t value);

/**
 * @brief Searches the corresponding node inside the table.
 * @return A pointer to the key node.
 */
t_hashtableEntry	*hashtableGet(const t_hashtable *table, const char *key);

/**
 * @brief Creates an allocated copy of src.
 * @return A pointer to the copy.
 */
t_hashtable	*hashtableDup(const t_hashtable *src);

/**
 * @brief Destroys allocated data and the hashTableHash table pointer.
 */
void	hashtableDestroy(t_hashtable *table);

# ifdef LIBHASHTABLE_IMPLEMENTATION

# ifndef LIBSTR_IMPLEMENTATION
#  define LIBSTR_IMPLEMENTATION
# endif
# include "libs/libstr/libstr.h"

static size_t	HASHTABLE_PRIVATE(hashTableHash)(const char *key)
{
	size_t	hashv;

	if (NULL == key)
		return (0);
	while (*key)
	{
		hashv += *key;
		++key;
	}
	return (hashv);
}

static t_hashtableEntry	*HASHTABLE_PRIVATE(hashtableEntryNew)(const char *key, size_t val)
{
	t_hashtableEntry	*new;

	new = malloc(sizeof(t_hashtableEntry));
	if (NULL == new)
		return (NULL);
	new->key = strDup(key);
	if (NULL == new->key)
	{
		free(new);
		return (NULL);
	}
	new->value = val;
	return (new);
}

static t_hashtableEntry	*HASHTABLE_PRIVATE(hashtableEntryDup)(const t_hashtableEntry *src)
{
	t_hashtableEntry	*dup;

	dup = hashtableEntryNew_private(src->key, src->value);
	if (NULL == dup)
		return (NULL);
	return (dup);
}


static int 	HASHTABLE_PRIVATE(hashtableEntryCompareKeys)(const char *key1, const char *key2)
{
	return (strCompare(key1, key2));
}

static void	hashtableEntryDestroy(t_hashtableEntry *entry)
{
	if (NULL == entry)
		return ;
	free(entry->key);
	// free(entry->value);
	free(entry);
	return ;
}

t_hashtable	*hashtableNew(size_t initial_capacity)
{
	t_hashtable	*new;

	new = malloc(sizeof(t_hashtable));
	if (NULL == new)
		return (NULL);
	new->bsize = initial_capacity * sizeof(t_hashtableEntry *);
	new->capacity = initial_capacity;
	new->data = calloc(1, new->bsize);
	if (NULL == new->data)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

t_hashtable	*hashtableSet(t_hashtable *table, const char *key, const size_t value)
{
	size_t		hashv;
	t_hashtableEntry	*entry;

	if (NULL == table || NULL == key)
		return (NULL);
	hashv = hashTableHash_private(key);
	entry = hashtableEntryNew_private(key, value);
	if (NULL == entry)
		return (NULL);
	if (hashv >= table->capacity)
	{
		t_llist	**old_data = table->data;

		table->data = realloc(table->data, (hashv + 1) * sizeof(t_llist *));
		if (NULL == table->data)
		{
			table->data = old_data;
			free(entry);
			return (NULL);
		}
		strMemSet(table->data + table->capacity, 0, (hashv + 1 - table->capacity) * sizeof(t_llist *));
		table->bsize = (hashv + 1) * sizeof(t_llist *);
		table->capacity = hashv + 1;
		if (NULL == llistPushBack(table->data + hashv, llistNew(entry)))
		{
			free(entry);
			return (NULL);
		}
		return (table);
	}

	if (NULL == *(table->data + hashv))
	{
		*(table->data + hashv) = llistNew(entry);
		if (NULL == *(table->data + hashv))
		{
			free(entry);
			return (NULL);
		}
		return (table);
	}

	t_llist	*node = llistGetFor(*(table->data + hashv), (t_llistCompareFn)&hashtableEntryCompareKeys_private, key);
	if (NULL == node)
	{
		if (NULL == llistPushBack(table->data + hashv, llistNew(entry)))
		{
			free(entry);
			return (NULL);
		}
		return (table);
	}
	((t_hashtableEntry *)node->data)->value = value;
	return (table);
}

t_hashtableEntry	*hashtableGet(const t_hashtable *table, const char *key)
{
	size_t	hashv;
	t_llist	*node;

	if (NULL == table || NULL == key)
		return (NULL);
	hashv = hashTableHash_private(key);
	if (hashv >= table->capacity)
		return (NULL);
	node = llistGetFor(*(table->data + hashv), (t_llistCompareFn)&hashtableEntryCompareKeys_private, key);
	if (NULL == node)
		return (NULL);
	return (node->data);
}

t_hashtable	*hashtableDup(const t_hashtable *src)
{
	size_t		index = 0;
	t_hashtable	*cpy;

	if (NULL == src)
		return (NULL);
	cpy = hashtableNew(src->capacity);
	if (NULL == cpy)
		return (NULL);
	while (index < src->capacity)
	{
		if (NULL != *(src->data + index))
		{
			*(cpy->data + index) = llistDup(*(src->data + index), (t_llistDupFn)&hashtableEntryDup_private, (t_llistDestroyFn)&hashtableEntryDestroy);
			if (NULL == *(cpy->data + index))
			{
				hashtableDestroy(cpy);
				return (NULL);
			}
		}
		++index;
	}
	return (cpy);
}

void	hashtableDestroy(t_hashtable *table)
{
	if (NULL == table)
		return ;
	if (NULL != table->data)
	{
		for (size_t i = 0; i < table->capacity; ++i)
		{
			if (NULL == *(table->data + i))
				continue;
			llistDestroy(table->data + i, (t_llistDestroyFn)&hashtableEntryDestroy);
		}
		free(table->data);
		table->data = NULL;
	}
	free(table);
	return ;
}

# endif // LIBHASHTABLE_IMPLEMENTATION

#endif // LIBHASHTABLE_H
