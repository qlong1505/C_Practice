
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void PrintElements(int *a, int len)
{
    printf("Print elements: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int ReturnMinIndex(int *array, int startIndex, int endIndex)
{
    int minIndex = startIndex;
    int index = startIndex;
    while (index <= endIndex)
    {
        if (array[minIndex] > array[index])
        {
            minIndex = index;
        }
        index++;
    }
    return minIndex;
}

void SwapTwoElements(int *array, int index1, int index2)
{
    //using XOR operation
    // printf("SwapTwoElements::Before %d,%d \n", array[index1], array[index2]);
    if (index1 != index2)
    {
        array[index1] ^= array[index2];
        array[index2] ^= array[index1];
        array[index1] ^= array[index2];
    }
    // printf("SwapTwoElements::After %d,%d \n", array[index1], array[index2]);
}
