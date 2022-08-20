#include "regex.h"

/**
 * regex_match - checks where given pattern matches a given string
 * @str: string to scan
 * @pattern: regluar expression
 *
 * Return: 1 if pattern matches, 0 if doesn't
 */
int regex_match(char const *str, char const *pattern)
{
	unsigned int i = 0, j = 0;

	for (i = 0, j = 0; str[i]; i++, j++)
	{
		if (str[i] == pattern[j])
			continue;
		else if (pattern[j] == '.')
			continue;
		else if (pattern[j] == '*')
		{
			if (pattern[j - 1] == '.')
			{
				while (pattern[j + 1] != str[i] && str[i])
					i++;
			}
			else
			{
				while (pattern[j - 1] == str[i])
					i++;
			}
			i--;
		}
		else if (pattern[j + 1] && pattern[j + 1] == '*')
			i--;
		else
			return (0);
	}
	return (1);
}
