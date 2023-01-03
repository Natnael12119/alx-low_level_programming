/**
 * File: 0-memset.c
 * Auth: Natnael Tewodros
 */

#include "main.h"

/*
 * _memset - Entry point
 * @s: pointer to memory area to fill with b
 * @b: value to fill memory area with
 * @n: number of bytes to fill with b
 *
 * Return: pointer to memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
