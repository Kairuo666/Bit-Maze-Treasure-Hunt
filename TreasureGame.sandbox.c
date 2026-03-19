#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>


// Treasure Game sandbox

int main()
{
    char password[] = "12345";
    char userinput[10];

    printf("This game is protected by a 5 character string password,\n\n");

    while (1)
    {
        printf("Please enter the password to proceed: ");
        scanf_s("%9s", userinput, (unsigned)_countof(userinput)); // scanf_s always needs a pass buffer size

        printf("\n");
        if (strcmp(userinput, password) == 0)
        {
            printf("Access granted.\n\n");
            break;
        }
        else
        {
            printf("Access Denied.\n\n");
        }
    }
    
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
}



