/**
 * File: 0-memset.c
 * Auth: Natnael Tewodros
 */

#include "main.h"

/**
 * _memset - Fills the first n bytes of the memory area pointe
 * @s: A pointer to the memory area to be filled.
 * @c: The character to fill the memory area with.
 * @n: The number of nytes to be filled.
 * description _memset: Over there
 *
 * Returd: A pointer to the filled memory area @s.
 */
void *_memset(void *s, int c, size_t n)
{
	unsigned int index;
	unsigned char *memory = s, value = c;

	for (index = 0; index < n; index++)
		memory[index] = value;

	return (memory);
}
