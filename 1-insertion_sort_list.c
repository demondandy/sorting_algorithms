#include "sort.h"

/**
 * insertion_sort_list - implements Insertion sort algorithm and it
 * works on a doubly linked list of integers to sort it in ascending
 * order
 * @list: Double pointer to the head of the linked list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *temp2;

	if (list == NULL || *list == NULL)
		return;
	temp = (*list)->next;
	while (temp != NULL)
	{
		temp2 = temp->next;
		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list(*list);
		}
		temp = temp2;
	}
}
