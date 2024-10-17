#include "sort.h"

void merge_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    size_t mid = size / 2;
    size_t i;
    int *left = array;
    int *right = array + mid;

    merge_sort(left, mid);
    merge_sort(right, size - mid);

    int l = 0, r = 0, a = 0;
    int left_size = mid;
    int right_size = size - mid;
    int *tmp = malloc(size * sizeof(int));

    if (!tmp)
        return;

    while (l < left_size && r < right_size)
    {
        if (left[l] < right[r])
        {
            tmp[a] = left[l];
            l++;
        }
        else
        {
            tmp[a] = right[r];
            r++;
        }
        a++;
    }

    while (l < left_size)
    {
        tmp[a] = left[l];
        l++;
        a++;
    }

    while (r < right_size)
    {
        tmp[a] = right[r];
        r++;
        a++;
    }

    for (i = 0; i < size; i++)
        array[i] = tmp[i];

    free(tmp);
}
