#include "lists.h"

/**
 * check_cycle - checks if a lniked list has loop
 * @list: list to check
 *
 * Return: 0 if false 1 if true
 */
int check_cycle(listint_t *list)
{
	listint_t *cur;
	listint_t *fut;

	if (list == NULL)
		return (0);

	cur = list;
	fut = cur->next;

	while (cur && fut)
	{
		if (cur == fut)
			return (1);
		cur = cur->next;
		fut = fut->next;
		if (fut != NULL)
			fut = fut->next;
	}

	return (0);
}