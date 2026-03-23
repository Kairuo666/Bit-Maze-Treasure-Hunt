#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>


int main()
{
    // Bitwise initialisation
    int i, j;
    char x[36];
    int disp[6][6];
    char shown[6][6];
    // Password initialisation
    char password[] = "12345";
    char userinput[10];
    // Maze
    int loc;



    // Password
    printf("[ this game is protected by a 5 character string password ]\n\n");

    while (1)
    {
        printf("You need to enter the password to proceed: ");
        scanf_s("%9s", userinput, (unsigned)_countof(userinput)); // scanf_s always needs a buffer size

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

    srand((unsigned int)time(NULL));


  // Bitwise Operation
 
  // T = trap
  // G = gold
  // . = unknown tile
  // X = visited
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {

            int trap = rand() % 2;          // bit  = 0
            int Gold = rand() % 2;       // bit  = 1
            int goldAmount = rand() % 16;   // bits = 4–7 (ranging with gold amount 1–15)

            int treasure = 0;
            treasure |= trap << 0;              // bit = 0
            treasure |= Gold << 1;           // bit = 1
            treasure |= (goldAmount & 0xF) << 4; // bits = 4–7 (ranging with gold amount 1-15)

            disp[i][j] = treasure;
        }
    }


    //printf("The 6x6 matrix:\n\n");
    //for (i = 0; i < 6; i++) {
    //    for (j = 0; j < 6; j++) {
    //        printf("%3d ", disp[i][j]); // 3d prints using 3 character spaces
    //    }
    //    printf("\n");
    //}



    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            shown[i][j] = '.';
        }
    }


    // Maze functionality

    while (1)
    {
        // Print player map
        printf("\nPlayer Map:\n\n");
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++) {
                printf("%c ", shown[i][j]);
            }
            printf("\n");
        }

        // Ask player for a location
        int loc;
        printf("\n");
        printf("(reminder, the list starts from 0)");
        printf("\nenter the number of the tile to reveal it (type -1 to quit): ");
        scanf_s("%d", &loc);

        if (loc == -1) {
            printf("game ended.\n");
            break;
        }

        int row = loc / 10;
        int col = loc % 10;

        if (row < 0 || row > 5 || col < 0 || col > 5) {
            printf("Invalid location.\n");
            continue;
        }

        // Decode treasure
        int treasure = disp[row][col];
        int trap = (treasure >> 0) & 1;
        int hasGold = (treasure >> 1) & 1;
        int goldAmount = (treasure >> 4) & 0xF;

        // Update visible map
        if (trap) {
            shown[row][col] = 'T';
            printf("You found a TRAP at (%d,%d)!\n", row, col);
        }
        else if (hasGold) {
            shown[row][col] = 'G';
            printf("You found GOLD (%d pieces) at (%d,%d)!\n", goldAmount, row, col);
        }
        else {
            shown[row][col] = 'X';
            printf("empty tile.\n");
        }
    }
}



