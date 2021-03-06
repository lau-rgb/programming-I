/*
2. Develop a tic - tac - toe game using a bidimensional array(3x3)
Init the array with value 0
Computer plays with value 1, choosen position is random!
User plays with value 2, input position should be asked
Check computer / user inputs positions are valid(not filled)
Check winning condition
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Tittle();
int DrawArray(int array[3][3]);
int IsLine(int array[3][3], int player);

int main()
{
	int player = 0;
	int winner = 0;
	int correct = 0;
	int row = 0, column = 0;
	int counter = 0;
	int array[3][3] = { { 0,0,0 },
						{ 0,0,0 },
						{ 0,0,0 } };
	srand(time(NULL));



	while (winner == 0)  // loop for all game
	{
		Tittle();
		DrawArray(array);

		//---------------------------player move----------------------------------
		correct = 0;
		while (correct == 0)
		{
			printf("\nWrite the coordinates ^^\n");
			printf("Row    :");
			scanf_s("%i", &row);
			printf("Column :");
			scanf_s("%i", &column);

			if ((row >= 1 && row <= 3) && (column >= 1 && column <= 3))
			{
				if (array[row - 1][column - 1] == 0)correct = 1;
			}
			else printf("Try again please\n");
		}
		array[row - 1][column - 1] = 2;
		counter++;
		if (counter >= 9)
		{
			break;
			winner = 3;
		}
		player = 2;
		winner = IsLine(array, player);
		if (winner == player)
		{
			system("cls");   //cleaning screen
			break;
		}

		//---------------------------computer move---------------------------------
		correct = 0;
		while (correct == 0)
		{
			row = ((rand() % 3) + 0);
			column = ((rand() % 3) + 0);
			if (array[row][column] == 0)correct = 1;
		}
		array[row][column] = 1;
		if (counter >= 9)
		{
			break;
			winner = 3;
		}
		player = 1;
		winner = IsLine(array, player);

		system("cls");   //cleaning screen
	}

	Tittle();
	DrawArray(array);

	if (winner == 1)printf("\nNICE, I WIN ^^\n");
	if (winner == 2)printf("\nOH, SO SAD. THIS TIME U WIN T_T\n");
	if (winner == 3) printf("\nTIE. NEXT TIME I WILL WIN uwu\n");

	return 0;
}

int Tittle()
{
	printf("***************************\n");
	printf("***     TIC TAC TOE     ***\n");
	printf("***************************\n");
	return 0;
}

int DrawArray(int array[3][3])
{
	printf("          1  2  3\n");
	for (int i = 0; i < 3; i++)
	{
		printf("\n     %i  ", i + 1);
		for (int j = 0; j < 3; j++) printf("  %i", array[i][j]);
	}
	printf("\n\n    1 IA - 2 PLAYER\n");
	return 0;
}

int IsLine(int array[3][3], int player)
{
	int result = 0;
	int rowCount = 0;
	int columnCount = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (array[i][j] == player)rowCount++;
			else rowCount = 0;
			if (array[i][j] == player)columnCount++;
			else columnCount = 0;
			
			if (rowCount == 3 || columnCount == 3)result = player;
		}
	}
	
	if ((array[0][0] == player && array[1][1] == player) && array[2][2] == player) result = player;
	if ((array[0][2] == player && array[1][1] == player) && array[2][0] == player) result = player;

	return result;
}