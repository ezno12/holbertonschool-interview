#include "substring.h"

/**
 * find_substring - finds all possible substrings containing list of words
 * @s: the string to scan
 * @words: the array of words all substrings must be concatenation of
 * @nb_words: the number of elements in the array words
 * @n: pointer to which to store the number of elements in the returned array
 *
 * Return: array storing each index in s at which a substring was found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word = 0, i = 0, match = 0, count = 0, j = 0, k = 0, I = 0;
	int *word_used = NULL, *indices = NULL;

	*n = 0;
	if (words == NULL)
		return (NULL);
	j = (nb_words * string_length(words[0]));
	i = allocate(&word_used, nb_words, &indices, (string_length(s) / j) + 1);
	if (i == -1)
		return (NULL);
	for (i = 0; s[i]; i++)
	{
		I = i;
		for (reset(&word_used, nb_words), word = 0; word < nb_words && s[i]; word++)
		{
			match = string_compare(s, i, words[word]);
			while (match != 0)
			{
				word_used[word] = 1;
				i += match;
				if (s[i] == '\0')
					break;
				for (count = 0, word = 0; word < nb_words; word++)
				{
					if (word_used[word] != -1)
						count++;
					match = string_compare(s, i, words[word]);
					if (match != 0)
						break;
				}
				if (count == nb_words)
					indices[k++] = (i - j);
			}
		}
		if (i != I || s[i] == '\0')
			i--;
	}
	free(word_used);
	*n = k;
	return (indices);
}

/**
 * allocate - allocates memory for int arrays
 * @word_used: pointer to first memory to allocate
 * @nb_words: number of words to allocate space for
 * @indices: pointer to second memory to allocate
 * @max_index: maximum number of indices possible to allocate for
 *
 * Return: -1 if failed, 0 if successful
 */
int allocate(int **word_used, int nb_words, int **indices, int max_index)
{
	*word_used = malloc(sizeof(int) * nb_words);
	if (*word_used == NULL)
		return (-1);
	reset(word_used, nb_words);
	*indices = malloc(sizeof(int) * max_index);
	if (*indices == NULL)
	{
		free(word_used);
		return (-1);
	}
	reset(indices, max_index);
	return (0);
}

/**
 * string_compare - compares two strings to see if one contains the other
 * @s1: the first string to compare, the longer of the strings
 * @i: the index of the first string to start from
 * @s2: the second string to compare, the shorter of the strings
 *
 * Return: length of the shorter word contained or 0 if no match
 */
int string_compare(char const *s1, unsigned int i, char const *s2)
{
	unsigned int j = 0;

	for (j = 0; s1[i] && s2[j]; i++, j++)
	{
		if (s1[i] != s2[j])
			return (0);
	}
	return (j);
}

/**
 * string_length - finds the length of a string
 * @str: the string to get length of
 *
 * Return: length of the string
 */
int string_length(char const *str)
{
	unsigned int i = 0;

	for (i = 0; str[i]; i++)
		continue;
	return (i);
}

/**
 * reset - sets all elements of array to -1
 * @array: pointer to the array to reset
 * @size: the size of the array to reset
 *
 */
void reset(int **array, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
		(*array)[i] = -1;
}
