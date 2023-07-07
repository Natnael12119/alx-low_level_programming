#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index of a decimal number.
 * @n:  is the decimal number to search for the bit value.
 * @index: is the position of the bit to retrieve.
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
