#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a doubly linked list of integers.
 * @list: A pointer to the head of the doubly linked list.
 */
void print_list(const listint_t *list)
{
	while (list)
	{
		printf("%d", list->n);
		if (list->next)
			printf(", ");
		list = list->next;
	}
	printf("\n");
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using an insertion sort algorithm.
 * @list: A pointer to the doubly linked list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *lead, *follow, *new, *temp;

	if (!list || !(*list) || !((*list)->next))
		return;

	follow = *list;
	lead = (*list)->next;

	while (lead)
	{
		new = lead->next;
		while (follow && lead->n < follow->n)
		{
			if (follow->prev)
				follow->prev->next = lead;
			else
				*list = lead;

			if (lead->next)
				lead->next->prev = follow;

			temp = lead->next;
			lead->next = follow;
			lead->prev = follow->prev;
			follow->next = temp;
			follow->prev = lead;

			print_list(*list);

			follow = lead->prev;
		}
		lead = new;
		if (lead)
			follow = lead->prev;
	}
}
