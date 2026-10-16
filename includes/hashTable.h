#ifndef HASHMAP_H
# define HASHMAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "hashTableNode.h"

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
	HTNode	**data;
}	HashTable;

/**
 * @brief Creates a new hash table.
 * @param initial_capacity The initial number of entries the table can store.
 * @return A pointer to the newly created hash table.
 */
HashTable	*HashTable_new(size_t initial_capacity);

/**
 * @brief Destroys allocated data and the hash table pointer.
 */
void	HashTable_destroy(HashTable *table);

/**
 * @brief Destroys the hash table data.
 */
void	HashTable_destroy_data(HashTable *table);

/**
 * @brief Searches the corresponding node inside the table.
 * @return A pointer to the key node.
 */
HTNode	*HashTable_get(const HashTable *table, const char *key);

/**
 * @brief Stores data inside the table if key is inexistent, updates it otherwise.
 * @return The updated hash table.
 */
HashTable	*HashTable_set(HashTable *table, const char *key, const size_t value);

/**
 * @brief Creates an allocated copy of src.
 * @return A pointer to the copy.
 */
HashTable	*HashTable_cpy(const HashTable *src);

/**
 * @brief Returns a pointer to the first valid entry in the table.
 * @return The entry's pointer.
 */
HTNode	*HashTable_first(HashTable *table);

/**
 * @brief Display the table.
 */
void	HashTable_display(HashTable *table);

#endif
