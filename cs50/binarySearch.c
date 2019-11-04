#include <stdio.h>
#include <stdlib.h>
int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
int len = sizeof(array) / sizeof(int);

int main(int argc, char *argv[])
{
    printf("size of array = %d\n", len);
    if (argc != 2)
    {
        printf("Need argument \n");
    }
    else
    {
        int value = atoi(argv[1]);
        if (len == 1)
        {
            if (value != array[0])
            {
                printf("Could not find value int the array \n");
            }
            else
            {
                printf("Found value %d at 0 index \n", value);
            }
        }
        else
        {
            printf("Argument value = %d\n", value);
            unsigned int start = 0;
            unsigned int end = len - 1;
            unsigned int mid;

            while (1)
            {

                mid = (start + end) / 2;
                printf("Start = %d, End = %d, Mid = %d\n", start, end, mid);
                if (array[mid] == value)
                {
                    printf("Found %d at index %d\n", value, mid);
                    break;
                }
                else if (array[mid] < value)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }

                if (start == end)
                {
                    if (value == array[start])
                    {
                        printf("Found %d at index %d\n", value, start);
                    }
                    else
                    {
                        printf("Could not find value int the array \n");
                    }
                    break;
                }
            }
        }
    }
}
