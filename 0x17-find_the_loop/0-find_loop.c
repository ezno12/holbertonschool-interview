#include "lists.h"
/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: it's a head of list to find loop
 * Return: node where loop is located otherwise NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *idk, *idk2;

	idk = head;
	idk2 = idk;
	while (idk && idk2 && idk2->next)
	{
		idk = idk->next;
		idk2 = idk2->next->next;
		if (idk == idk2)
		{
			idk = head;
			while (idk && idk2)
			{
				if (idk == idk2)
					return (idk);
				idk = idk->next;
				idk2 = idk2->next;
			}
		}
	}
	return ('\0');
}
