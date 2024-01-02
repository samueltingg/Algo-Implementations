
void	swap_qs(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * @brief split stack to left & right of pivot,
 * 			returns pivot_index after partition
 */
int	partition(int *stack, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	i = start;
	j = start - 1;
	pivot = stack[end]; // pivot set as end_index
	while (i <= end)
	{
		if (stack[i] <= pivot)
		{
			j++;
			if (i > j)
				swap_qs(&stack[i], &stack[j]);
		}
		i++;
	}
	return (j);
}

void	quick_sort(int *stack, int start, int end)
{
	int pivot_index;

	if (start < end) // base case
	{
		pivot_index = partition(stack, start, end);
		quick_sort(stack, start, (pivot_index - 1)); // sort LHS
		quick_sort(stack, (pivot_index + 1), end);   // sort RHS
	}
}