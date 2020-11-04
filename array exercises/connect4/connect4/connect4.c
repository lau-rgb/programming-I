/*
3. Write a program to play Connect-Four, similar to tic-tac-toe
Use a bi-dimensional array to simulate the grid
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int PrintArray(int array[6][7]);
int Tittle();
int IsLine(int array[6][7], int player);

int main()
{
	int win = 0;
	int correct = 0;
	int column = 0;
	int player = 0;
	int counter = 0;       //used for count in different situations
	int array[6][7] = {
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},};

	srand(time(NULL));

	while (win == 0)
	{
		Tittle();
		PrintArray(array);

		correct = 0;
		while (correct == 0)
		{
			printf("\n\nChoose a column: ");
			scanf_s("%i", &column);
			if (column <= 7 && column >= 1)
			{
				if (array[0][column - 1] == 0) correct = 1;
			}
		}

		player = 2;
		
		//SettArray(&array, &column, &player);
		counter = 5;
		while (counter >= 0)
		{
			if (array[counter][column - (player - 1)] == 0)
			{
				array[counter][column - (player - 1)] = player;
				counter = -1;
			}
			counter--;
		}

		win = IsLine(array, player);
		if (win != 0)
		{
			system("cls");   //cleaning screen
			break;
		}

		correct = 0;
		column = ((rand() % 6) + 0);
		while (correct==0)
		{
			if (array[0][column] == 0) correct = 1;
			else column = ((rand() % 6) + 0);
		}
		
		player = 1;
		
		//SettArray(&array, &column, &player);
		counter = 5;
		while (counter >= 0)
		{
			if (array[counter][column - (player - 1)] == 0)
			{
				array[counter][column - (player - 1)] = player;
				counter = -1;
			}
			counter--;
		}

		win = IsLine(array, player);

		system("cls");   //cleaning screen
	}

	Tittle();
	PrintArray(array);

	if (win == 1)printf("\nNICE, I WIN ^^\n");
	if (win == 2)printf("\nOH, SO SAD. THIS TIME U WIN T_T\n");
	if (win == 3) printf("\nTIE. NEXT TIME I WILL WIN uwu\n");

	return 0;
}

int Tittle()
{
	printf("*************************\n");
	printf("***     CONNECT 4     ***\n");
	printf("*************************\n");
	return 0;
}

int PrintArray(int array[6][7])
{
	printf("\n   1  2  3  4  5  6  7\n");
	for (int i = 0; i < 6; i++)
	{
		printf("\n   ");
		for (int j = 0; j < 7; j++) printf("%i  ",array[i][j]);
	}
	printf("\n\n     1 IA - 2 PLAYER\n");
	return 0;
}

void SettArray(int* array[6][7], int* column, int* player)
{
	int counter = 5;
	while (counter >= 0)
	{
		if (*array[counter][*column - (*player - 1)] == 0)
		{
			*array[counter][*column - (*player - 1)] = 2;
			counter = -1;
		}
	}
}

int IsLine(int array[6][7], int player)
{
	// to comprove columns and rows
	int result = 0;
	int counter = 0;
	int previousFilled = 0;

	for (int i = 0; i < 6; i++)  //looks if there is a line in any row
	{
		previousFilled = 1;
		for (int j = 0; j < 7; j++) 
		{
			if (array[i][j] == player)
			{
				if (previousFilled == 1) counter++;
			}
			else
			{
				previousFilled = 0;
				counter = 0;
			}
			if (counter >= 4) result = player;
		}
	}
	
	for (int j = 0; j < 7; j++)  //looks if there is a line in any column
	{
		previousFilled = 1;
		for (int i = 0; i < 6; i++)
		{
			if (array[i][j] == player)
			{
				if (previousFilled == 1) counter++;
			}
			else
			{
				previousFilled = 0;
				counter = 0;
			}
			if (counter >= 4) result = player;
		}
	}

	//me falta comprobar las diagonales T_T

	return result;  // te retorna q jugador es el ganador
}