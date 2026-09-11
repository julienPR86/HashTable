#include "hash.h"

size_t	strvalue(const char *s)
{
	size_t	v = 0;

	if (NULL == s)
		return (0);
	while (*s)
	{
		v += *s;
		++s;
	}
	return (v);
}

size_t	hash(const char *key)
{
	size_t	hashv;

	hashv = strvalue(key);
	return (hashv);
}
