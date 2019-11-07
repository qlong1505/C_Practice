#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void ShiftAndInsert(int *array, int unsortIndex, int positionIndex, int arrayLength)
{

    int tmp = *(array + unsortIndex);
    // printf("tmp: %d, index: %d\n", tmp, unsortIndex);
    // PrintElements(array, arrayLength);
    // printf("%d, index: %d\n", array[unsortIndex], unsortIndex);
    for (int j = unsortIndex; j > positionIndex; j--)
    {
        array[j] = array[j - 1];
        // PrintElements(array, arrayLength);
    }
    array[positionIndex] = tmp;
    // PrintElements(array, arrayLength);
}

void InsertionSort(int *array, int arrayLength)
{
    int startIndex = 0;
    int unsortIndex = 1;

    while (unsortIndex < arrayLength)
    {
        /// if less than the first item
        if (array[unsortIndex] < array[startIndex])
        {
            // SwapTwoElements(array, startIndex, unsortIndex);
            ShiftAndInsert(array, unsortIndex, startIndex, arrayLength);
        }
        else
        {
            for (int i = startIndex; i < unsortIndex; i++)
            {
                if (array[i] <= array[unsortIndex] && array[i + 1] > array[unsortIndex])
                {
                    ShiftAndInsert(array, unsortIndex, i + 1, arrayLength);
                    break;
                }

                // if (array[unsortIndex]<)
            }
        }
        // printf("%d: ", unsortIndex);
        // PrintElements(array, arrayLength);
        unsortIndex++;
    }
}

int main(int argc, char *argv[])
{
    int *array = (int *)calloc(argc - 1, sizeof(int));
    int arrayLength = argc - 1;
    // printf("argc %d=\n", argc);
    // printf("malloc size %d=\n", (argc - 1) * sizeof(int));
    // printf("size of array %ld\n",sizeof(array));

    for (int i = 1; i < argc; i++)
    {
        array[i - 1] = atoi(argv[i]);
    }
    printf("Array before: ");
    PrintElements(array, arrayLength);

    // printf("Min index is %d\n", ReturnMinIndex(array, 0, arrayLength - 1));

    InsertionSort(array, arrayLength);

    printf("Array after: ");
    PrintElements(array, arrayLength);
    // printf("Min index is %d\n", ReturnMinIndex(array, 0, arrayLength - 1));
}