/****************************************************************************
*
*	TEST EXERCISE 01: Rock, Paper, Scissor
*
*	Student name: Laura Isidro
*
*   - Game consists of multiple rounds and the winner must win 2 rounds.
*   - Game must finish if player decides to not continue with the game.
*   - Program must show every round: Played Rounds, Player Wins, CPU Wins.
*   - Program must show at the end: Total Games Won by Player and CPU.
*   - Required functions must be implemented and used.
*
*   WARNING! REMEMBER:
*
*	    - Program must compile. No compiling program is a 0 in the mark.
*	    - Program must be perfectly tabulated and spaced.
*	    - Program must follow required naming conventions.
*	    - Program must show screen results organized and styled.
*
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char PlayerSelection(void);
char CpuSelection(void);
void CheckResult(char playerSelection, char cpuSelection, int* result);

int main()
{
    int keepPlaying = 1;
    int gamesWonPlayer = 0;
    int gamesWonCpu = 0;
    int roundsWonPlayer = 0;
    int roundsWonCpu = 0;
    char playerSelection = '-';
    char cpuSelection = '-';
    int roundResult = 0;
    int roundsCount = 0;

    srand(time(NULL));

    // TODO 1: Start the game loop (1p) 
    while (keepPlaying == 1)
    {
        roundsCount = 0;
        gamesWonCpu = 0;
        gamesWonPlayer = 0;

        while (roundsCount >= 0)
        {
            // Get player selection
            playerSelection = PlayerSelection();    // TODO 2: Implement function (2p)

            // Get CPU selection
            cpuSelection = CpuSelection();          // TODO 3: Implement function (1p)

            // Check round results
            CheckResult(playerSelection, cpuSelection, &roundResult);   // TODO 4: Implement function (3p)

            // TODO 5: Check round results, save in corresponding variables and print info on screen (1p)
            if (roundResult == 0) printf("\nTie");

            if (roundResult == 1)
            {
                printf("\nWow, you win this round");
                gamesWonPlayer++;
            }

            if (roundResult == 2)
            {
                printf("\nThe CPU wins this round ^^");
                gamesWonCpu++;
            }

            // TODO 6: Check game results, save in corresponding variables and print info on screen (1p)
            roundsCount++;

            printf("\n\nTotal rounds: %i", roundsCount);
            printf("\nPlayer wins: %i", gamesWonPlayer);
            printf("\nCPU wins: %i\n\n", gamesWonCpu);

            // TODO 7: Reset required variables and show required messages for next game (or finish) (1p)
            if (gamesWonCpu >= 2 || gamesWonPlayer >= 2) roundsCount = -1;
            else
            {
                system("pause");
                system("cls");
            }
        }

        if (gamesWonCpu >= 2) printf("The CPU wins the game\n\n");
        if (gamesWonPlayer >= 2) printf("The Player wins the game\n\n");

        printf("Do you want to play again? yes (1) no (2) ");
        scanf_s("%i", &keepPlaying);

        if (keepPlaying < 1 || keepPlaying>2)
        {
            printf("Wrong answer. Try again: ");
            scanf_s("%i", &keepPlaying);
        }

        system("pause");
        system("cls");
    }

    printf("See you next time ^^\n\n");

    system("pause");

    return 0;
}

// Check player selection
char PlayerSelection(void)
{
    // TODO 2: This function must ask player for selection ('r' - Rock, 'p' - Paper, 's' - Scissor),
    // Selection must be validated before returned. (2p)
    char playerElection = ' ';
    int correct = 0;

    printf("Options:\nr. Rock\np. Paper\ns. Scissors\n\nWrite the character: ");

    while (correct == 0)
    {
        scanf_s("%c", &playerElection);

        if ((playerElection == 'p' || playerElection == 'r') || playerElection == 's') correct = 1;
        else  printf("Your answer is wrong: ");
    }

    return playerElection;
}


// Check CPU selection
char CpuSelection(void)
{
    // TODO 3: This function must return CPU selection ('r' - Rock, 'p' - Paper, 's' - Scissor),
    // Selection must be calculated randomly. (1p)
    char selection = ' ';
    int cpuElection = 0;

    cpuElection = ((rand() % 3) + 1);

    if (cpuElection == 1) selection = 'r';
    if (cpuElection == 2) selection = 'p';
    if (cpuElection == 3) selection = 's';

    return selection;
}

// Check results for the round
void CheckResult(char playerSelection, char cpuSelection, int* result)
{
    // TODO 4: This function must check which one of the two players (Player, CPU) is the winner for 
    // the round and return the result by reference: 1-Player, 2-CPU. (3p)
    if (playerSelection == cpuSelection) *result = 0;

    if (playerSelection == 'r')
    {
        if (cpuSelection == 'p') *result = 2;
        if (cpuSelection == 's') *result = 1;
    }

    if (playerSelection == 'p')
    {
        if (cpuSelection == 'r') *result = 1;
        if (cpuSelection == 's') *result = 2;
    }
    
    if (playerSelection == 's')
    {
        if (cpuSelection == 'r') *result = 2;
        if (cpuSelection == 'p') *result = 1;
    }

}
