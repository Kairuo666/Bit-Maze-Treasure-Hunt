#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


// Treasure Game sandbox

int main()
{
    // 6x6 grid of randoms
    int i, j;
    char x[36];
    int disp[6][6];

    srand(time(NULL));

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            disp[i][j] = rand() % 10;
        }
    }


    printf("The 6x6 matrix:\n\n");
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d ", disp[i][j]);
        }
        printf("\n");
    }

    printf("Hello world");
    return 0;
}



