#include <stdio.h>
#include <stdlib.h>

#define row 8
#define column 10

/*------------------- FUNCTION TO COUNT LIVE NEIGHBOUR CELLS --------------------*/

int LiveCount(int grid[row][column], int r, int c)
{
    int i, j, count=0;
    for(i = r-1; i <= r+1; i++)
    {
        for(j = c-1; j <= c+1; j++)
        {
            if((i == r && j == c) || (i<0 || j<0) || (i >= row || j >= column))
            {
                continue;
            }
            if(grid[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    /*------------------ INITIALIZERS -------------------*/

    int LiveCells;
    int i, j;
    int grid[row][column] = {0};
    int next[row][column];
    int generation_count, x, y;
    char ch;

    printf("Enter generation count: ");
    scanf("%d", &generation_count);

    printf("Enter cell coordinates to make alive [x, y]:\n");

    /*---------------- TAKING INPUTS ---------------*/

    for(i=0; ; i++)
    {
        scanf("%d %d", &x, &y);
        grid[x][y] = 1;

        if(x == -1 || y == -1)
            break;
    }

    /*---------------- PRINTING INITIAL GRID ------------------*/

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    /*---------------- CHECKING CONDITIONS OF NEIGHBOURING CELLS --------------*/

    do
    {
        for(i=0; i<row; i++)
        {
            for(j=0; j<column; j++)
            {
                LiveCells = LiveCount(grid,i,j);
                if(grid[i][j] == 1 && (LiveCells == 2 || LiveCells == 3))
                {
                    next[i][j] = 1;
                }

                else if(grid[i][j] == 0 && LiveCells == 3)
                {
                    next[i][j] = 1;
                }

                else
                {
                    next[i][j] = 0;
                }
            }
        }

        /*------------- PRINTING THE NEXT GENERATION ----------------*/

        printf("\nNext Generation:\n");

        system("cls");       /*-------------NOT SURE-----------*/

        for(i=0; i<row; i++)
        {
            for(j=0; j<column; j++)
            {
                printf("%d ", next[i][j]);
            }
            printf("\n");
        }

//    printf("\n");

        /*----------------- UPDATING GRID VALUES -------------------*/

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<column; j++)
            {
                grid[i][j] = next[i][j];
//            printf("%d ", grid[i][j]);
            }
//        printf("\n");
        }

    }
    while(generation_count-- > 0);

    return 0;
}

