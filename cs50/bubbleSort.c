#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void BubbleSort(int *array, int arrayLength)
{
    int swapCounter = -1;
    // int i=0;
    int end = arrayLength - 1;
    while (swapCounter != 0)
    {
        ///reset swapCounter
        swapCounter = 0;

        for (int i = 0; i < end; i++)
        {
            //compare two next array
            if (array[i] > array[i + 1])
            {
                SwapTwoElements(array, i, i + 1);
                swapCounter++;
            }
        }
        end--;
    }
}

int main(int argc, char *argv[])
{
    int *array = malloc((argc - 1) * sizeof(int));
    int arrayLength = argc - 1;

    for (int i = 1; i < argc; i++)
    {
        array[i-1] = atoi(argv[i]);
    }
    printf("Array before: ");
    PrintElements(array, arrayLength);

    // printf("Min index is %d\n", ReturnMinIndex(array, 0, arrayLength - 1));

    BubbleSort(array, arrayLength);

    printf("Array after: ");
    PrintElements(array, arrayLength);
    // printf("Min index is %d\n", ReturnMinIndex(array, 0, arrayLength - 1));
}