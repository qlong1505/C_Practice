/*
 ============================================================================
 Name        : LIFX_Long_Tran.c
 Author      : Long Tran
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define COL 4
#define ROW 4
#define GRIDLENGTH 16
#define MAX 16
void push(int *stack, int item, int *top)
{

    if (*top == MAX - 1) // Checking Array is full or not.
    {
        printf("Overflow\n");
    }
    else
    {
        *top += 1; // top = top + 1
        stack[*top] = item;

        printf("pushed %d to the stack at index %d\n", item, *top);
    }
    return;
}
int pop(int *stack, int *top)
{
    int item;
    if (*top == -1) // Checking Array is empty or not.
    {
        printf("Underflow\n");
        return -1;
    }
    item = stack[*top];
    printf("pop %d from the stack at index %d\n", item, *top);
    *top -= 1; //	top = top - 1

    return item;
}

bool isVisited(int *visitedArray, int item, int *top)
{
    for (int i = 0; i <= *top; i++)
        if (item == visitedArray[i])
        {
            printf("Item %d has been Visited\n", item);
            return true;
        }
    printf("Item %d has NOT been Visited\n", item);
    return false;
}

bool search_word(char *wordGrid, int row, int col, char *wordtoFind)
{

    // printf("wordtoFind: %s\n", wordtoFind);
    int wordLength = strlen(wordtoFind);
    int xMove[] = {0, -1, +1, -1, 1, 0, -1, 1};
    int yMove[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dirNum = sizeof(xMove) / sizeof(int);
    int *visitedArray = malloc(16 * sizeof(int));
    int *adjArray = malloc(16 * sizeof(int));
    int topVisited = -1;
    int topAdj = -1;

    if (wordGrid[row * 4 + col] != wordtoFind[0])
    {
        return false;
    }
    else
    {
        //push index to visited
        printf("FOUND matched letter: %c\n", wordtoFind[row * 4 + col]);
        printf("push visited array\n");
        push(visitedArray, row * 4 + col, &topVisited);

        // printf("push adjacent array\n");
        for (int dir = 0; dir < dirNum; dir++)
        {
            int i = row + xMove[dir];
            int j = col + yMove[dir];
            if (i < 0 || i >= ROW || j < 0 || j >= COL)
            {
                continue;
            }
            else
            {
                printf("push adjacent array\n");
                push(adjArray, i * 4 + j, &topAdj);
            }
        }
    }
    // return false;

    // for (int index = 1; index < wordLength; index++)

    int index = 1;
    while (1)
    {

        /* code */

        int pop_item = pop(adjArray, &topAdj);
        if (wordtoFind[index] == wordGrid[pop_item])
        {
            printf("FOUND matched letter: %c\n", wordtoFind[pop_item]);
            printf("push visited array\n");
            push(visitedArray, pop_item, &topVisited);

            for (int dir = 0; dir < dirNum; dir++)
            {
                int i = (pop_item / 4) + xMove[dir];
                int j = (pop_item % 4) + yMove[dir];
                if (i < 0 || i >= ROW || j < 0 || j >= COL)
                {
                    continue;
                }
                else if (!isVisited(visitedArray, i * 4 + j, &topVisited))
                {
                    push(adjArray, i * 4 + j, &topAdj);
                }
            }
            index++;
        }

        if (index == wordLength)
        {
            return true;
        }
        if (topAdj == -1)
        {
            return false;
        }
    }

    // for (int dir = 0; dir < dirNum; dir++)
    // {
    //     int letterIndex;
    //     int rowS = row + xMove[dir];
    //     int colS = colS + yMove[dir];

    //     for (letterIndex = 1; letterIndex < wordLength; letterIndex++)
    //     {
    //         if (rowS < 0 || rowS >= ROW || colS < 0 || colS >= COL)
    //         {
    //             break;
    //         }

    //         if (wordtoFind[letterIndex] != wordGrid[rowS * +col])
    //         {
    //             break;
    //         }

    //         rowS += xMove[dir];
    //         colS += yMove[dir];
    //     }
    //     if (letterIndex == wordLength)
    //     {
    //         return true;
    //     }
    //     return false;
    // }
}

int main(int argc, char *argv[])
{
    // puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
    // printf("%d\n", argc);

    if (argc == 3)
    {
        char *pathWordsFile = argv[1];
        // char wordGrid[ROW][COL];
        char *wordGrid = malloc(ROW * COL);
        strcpy(wordGrid, argv[2]);
        unsigned char wordGridLength = strlen(wordGrid);

        if (wordGridLength != GRIDLENGTH) /*Not valid WordGrid */
        {
            return 0;
        }
        else
        {
            for (int iRow = 0; iRow < ROW; iRow++)
            {
                for (int iCol = 0; iCol < COL; iCol++)
                {
                    printf("%c ", wordGrid[iRow * 4 + iCol]);
                }
                printf("\n");
            }

            for (int iCol = 0; iCol < COL; iCol++)
            {
                for (int iRow = 0; iRow < ROW; iRow++)
                {

                    FILE *fp;
                    fp = fopen(pathWordsFile, "r");
                    int flag = 0;
                    char buffer[100];
                    strcpy(buffer, "");

                    if (NULL == fp)
                    {
                        printf("Could not open the file");
                        return -1;
                    }

                    while (!feof(fp))

                    {

                        fgets(buffer, 100, fp);
                        // printf("buffer: %s", buffer);
                        if (search_word(wordGrid, iCol, iRow, buffer))
                        {
                            printf("FOUND this pattern %s", buffer);
                        }
                    }
                }
            }
        }
    }

    else
    {
        printf("Need to fill enough argument. 1st is PATH, 2nd is GRID word");
        return 0;
    }

    return EXIT_SUCCESS;
}
