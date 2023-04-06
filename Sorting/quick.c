#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for(int j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

void quicksort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

void printArr(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int data[] = {8 , 7 , 2, 1, 0 ,9 , 6};
	int n = sizeof(data) / sizeof(data[0]);

	printf("Unsorted Array\n");
	printArr(data, n);

	quicksort(data, 0, n - 1);

	printf("Sorted array in ascending order : \n");
	printArr(data, n);
}