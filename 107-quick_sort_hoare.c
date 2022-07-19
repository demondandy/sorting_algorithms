#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * partition - detrimines the partition for the quicksort using
 *             the Hoare partition scheme
 * @array: array to be sorted
 * @lo: lowest index of the partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int temp, pivot;

	pivot = array[hi];
	while (lo <= hi)
	{
		while (array[lo] < pivot)
			lo++;
		while (array[hi] > pivot)
			hi--;
		if (lo <= hi)
		{
			if (lo != hi)
			{
				temp = array[lo];
				array[lo] = array[hi];
				array[hi] = temp;
				print_array(array, size);
			}
			lo++;
			hi--;
		}
	}
	return (hi);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to be sorted
 * @lo: lowest index of the partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: nothing
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quicksort(array, lo, pivot, size);
		quicksort(array, pivot + 1, hi, size);

	}
}

/**
 * quick_sort_hoare - driver program for implementation of quick sort
 *                    algorithm using hoare scheme
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
