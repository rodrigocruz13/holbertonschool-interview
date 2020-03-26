#include <stdio.h>
#include <stdlib.h>


/**
 * is_palindrome- finds if a number is palindrome
 * @n: unsigned long number
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
	unsigned long original_num = 0;
	unsigned long remainder = 0;
	unsigned long reversed_num = 0;

	original_num = n;
	while (n != 0)
	{
		remainder = n % 10;
		reversed_num = reversed_num * 10 + remainder;
		n = n / 10;
	}

	if (original_num == reversed_num)
		return (1);

	return (0);
}
