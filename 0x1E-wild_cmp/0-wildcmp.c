#include "holberton.h"

/**
* wildcmp - Compares 2 strings and returns 1 if the strings can be considered
* identical, otherwise return 0.
* @s1: 1st string
* @s2: 2nd string. It may contain wildcard pattern *
* Return: 1 if strings match, 0 otherwise
*/

int wildcmp(char *s1, char *s2)
{
	int cmp1, cmp2;

	if (!*s1)
	{
		if (*s2 == '*')
		{
			cmp1 = wildcmp(s1, s2 + 1);
			return (cmp1);
		}

		cmp2 = (*s2 == '\0') ? 1 : 0;

		return (cmp2);
	}

	if (*s2 == '*')
	{
		cmp1 = wildcmp(s1, s2 + 1);
		cmp2 = wildcmp(s1 + 1, s2);
		return (cmp1 || cmp2);
	}
	if (*s1 == *s2)
	{
		cmp1 = wildcmp(s1 + 1, s2 + 1);
		return (cmp1);
	}

	return (0);
}
