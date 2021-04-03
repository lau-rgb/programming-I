/*
Write a program to keep the clasification for the next FIFA game. We need to
store 10 possible teams, each team should contain the following info:

Played games count
Won games count
Lost games count
Drawn games count
Goals in favour
Goals against

Program should include a menu to:
Introduce new data
Update existing data
Write the first team on the table
Write the last team on the table
Show all the data
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct Team {
	int playedGames;
	int wonGames;
	int lostGmaes;
	int drawnGames;
	int goalsFavour;
	int goalsAgainst;
}Team;

int main()
{
	Team t01 = { 0 };
	Team t02 = { 0 };
	Team t03 = { 0 };
	Team t04 = { 0 };
	Team t05 = { 0 };
	Team t06 = { 0 };
	Team t07 = { 0 };
	Team t08 = { 0 };
	Team t09 = { 0 };
	Team t10 = { 0 };
	int desicion = 0;
	int endProgram = 0;
	int team = 0;

	printf("Welcome to the FIFA clasification\n");
	
	while (endProgram == 0)
	{
		printf("\n1. Introduce new data");
		printf("\n2. Update existing data");
		printf("\n3. Write the first team on the table");
		printf("\n4. Write the last team on the table");
		printf("\n5. Show all the data");
		printf("\nWhat do you want to do? ");
		scanf_s("%i", &desicion);

		system("cls");

		switch (desicion)
		{
		case 1:
			printf("You have 10 slots. Chose one: ");
			scanf_s("%i", &team);
			break;

		default:
			printf("Try again\n");
			break;
		}

		

		system("pause");
		system("cls");
	}

	return 0;
}

