/*
1. Write a program that asks user for a word string and do the following:
Read the stringand print it on the screen
Print the string reversed on the screen
Save the string reversed in another array
Check if the string is a palindromeand print it on screen
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>		//strlen

int main()
{
	char message[100] = { 0 };
	char messageRev[100] = { 0 };
	int messageLength = 0;

	printf("Introduce one string: ");
	gets(message);
	messageLength = strlen(message);	//te calcula cuanto de largo es 

	printf("Your string reversed is: ");

	for (int i = messageLength - 1, j = 0; i >= 0; i--, j++)
	{
		printf("%c", message[i]);
		messageRev[j] = message[i];
	}

	if (strcmp(message, messageRev) == 0) //return the first position that are diferent
	{
		printf("The word is palindrome");
	}

	system("pause");

	return 0;
}