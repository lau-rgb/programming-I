/*
  2. Develop a tic-tac-toe game using a bidimensional array (3x3)
    - Init the array with `value 0`
    - Computer plays with `value 1`, choosen position is random!
    - User plays with `value 2`, input position should be asked
    - Check computer/user inputs positions are valid (not filled)
    - Check winning condition
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int IsLine(int array[3][3], int player);

int main()
{
    int table[3][3] = { 0 };

    int cpuX = 0, cpuY = 0;
    int cpuValid = 0;

    int playerX = 0, playerY = 0;
    int playerValid = 0;
    int player = 0;

    int round = 0;
    int winner = 0;    // 0-NoWinner, 1-CPU, 2-Player

    srand(time(NULL));

    while (winner == 0)
    {
        // CPU play
        while (cpuValid == 0)
        {
            cpuX = rand() % 3;
            cpuY = rand() % 3;

            // TODO: Check is the cpu position is valid
            if (table[cpuY][cpuX] == 0)
            {
                table[cpuY][cpuX] = 1;
                cpuValid = 1;
            }
        }

        // comprobing the lines and winner
        round++;
        player = 1;
        //winner = IsLine(table,player);
        //if (winner==0 || round >= 9)winner = 3;
        if (winner != 0) break;

        printf("CPU turn, movement: [%i][%i]\n\n", cpuY, cpuX);

        // Print the table
        printf("-------------\n");
        for (int y = 0; y < 3; y++)
        {
            printf("| %i | %i | %i |\n", table[y][0], table[y][1], table[y][2]);
            printf("-------------\n\n");
        }

        // Player play
        while (playerValid == 0)
        {
            printf("\nPlayer turn, movement (i.e. 2,1): ");
            scanf_s("%i,%i", &playerY, &playerX);

            // Check if player position is valid
            if (((playerX >= 0) && (playerY < 3)) &&
                ((playerY >= 0) && (playerY < 3)) &&
                (table[playerY][playerX] == 0))
            {
                table[playerY][playerX] = 2;
                playerValid = 1;
            }
            else printf("Player movement not valid! Try again!\n\n");
        }

        // comprobing the lines and winner
        round++;
        player = 2;
        winner = IsLine(table, player);
        if (winner == 0 || round >= 9)winner = 3;
        if (winner != 0) break;

        // TODO: Check winning condition

        // Reset state for next loop
        cpuValid = 0;
        playerValid = 0;

        system("cls");  // Clear the screen
    }

    // Print the winner
    if (winner == 1) printf("CPU wins... you lose!\n");
    else if (winner == 2) printf("Player wins! Congratulations!\n");
    else if (winner == 3)printf("Tie. Nobody wins");

    return 0;
}

int IsLine(int array[3][3], int player)
{
    int result = 0;
    int columnCount = 0;
    int rowCount = 0;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < (2); j++)
        {
            if (array[i][j] == player) columnCount++;        //para comprobar linea en horizontal
            else rowCount = 0;
            if (array[j][i] == player) rowCount++;        //para combrobar linea en vertical
            else columnCount = 0;

            if (rowCount == 3 || columnCount == 3) result = player;
        }
    }

    if ((array[0][0] == array[1][1]) && array[2][2])result = player;
    if ((array[2][0] == array[1][1]) && array[0][2])result = player;

    return result;
}