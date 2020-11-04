/*
3. Write a program to play Connect-Four, similar to tic-tac-toe
Use a bi-dimensional array to simulate the grid
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int PrintArray(int array[6][7]);
int Tittle();

int main()
{
	int win = 0;
	int correct = 0;
	int counter = 0;
	int column = 0;
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

		SettArray(&array, &column);    //-----------------no se como va T_T----------------------
		

		correct = 0;
		column = ((rand() % 6) + 0);
		while (correct==0)
		{
			if (array[0][column] == 0) correct = 1;
			else column = ((rand() % 6) + 0);
		}
		counter = 5;
		while (counter >= 0)
		{
			if (array[counter][column] == 0)
			{
				array[counter][column] = 1;
				counter = -1;
			}
		}
		

		system("cls");   //cleaning screen
	}



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

void SettArray(int &array[6][7], int &column)
{
	int counter = 5;
	while (counter >= 0)
	{
		if (array[counter][column - 1] == 0)
		{
			array[counter][column - 1] = 2;
			counter = -1;
		}
	}
}