#include "main.h"

/**
 * binary_to_uint - converts a binary string to an unsigned integer.
 * @b: is a string that contains a binary number to be converted.
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int res = 0;
	int base = 1, i = 0;

	if (b == NULL)
		return (0);

	while (b[i + 1])
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		i++;
	}

	while (i >= 0)
	{
		res += ((b[i] - '0') * base);
		base *= 2;
		i--;
	}


	return (res);

}
