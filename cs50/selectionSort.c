#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void SelectionSort(int *array, int arrayLength)
{
    int min_index = ReturnMinIndex(array, 0, arrayLength - 1);

    // for (int i = 0; i < arrayLength; i++)
    int i = 0;
    while (i < arrayLength)
    {

        SwapTwoElements(array, i, min_index);
        // printf("%d ", i);
        // PrintElements(array, arrayLength);
        i++;
        min_index = ReturnMinIndex(array, i, arrayLength - 1);
        // printf("Min is %d at index %d \n", array[min_index], min_index);
        // PrintElements(array, arrayLength);
    }
}

int main(int argc, char *argv[])
{
    int *array = malloc((argc - 1) * sizeof(int));
    int arrayLength = argc - 1;

    for (int i = 1; i < argc; i++)
    {
        array[i - 1] = atoi(argv[i]);
    }
    printf("Array before: ");
    PrintElements(array, arrayLength);

    // printf("Min index is %d\n", ReturnMinIndex(array, 0, arrayLength - 1));

    SelectionSort(array, arrayLength);

    printf("Array after: ");
    PrintElements(array, arrayLength);

    free(array);
    // printf("Min index is %d\n", ReturnMinIndex(array, 0, arrayLength - 1));
}