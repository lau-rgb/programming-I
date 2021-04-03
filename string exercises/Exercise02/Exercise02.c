/*
2. Write a program that asks user for a sentence and count how many times
every vowel appears on it. Print the results on the screen.
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char message[100] = { 0 };
	int messageLength = 0;
	int aeiou[5] = { 0 };

	printf("Introduce one string: ");
	gets(message);
	messageLength = strlen(message);

	for (int i = 0; i <= messageLength; i++)
	{
		if (message[i] == 'a') aeiou[0]++;
		if (message[i] == 'e') aeiou[1]++;
		if (message[i] == 'i') aeiou[2]++;
		if (message[i] == 'o') aeiou[3]++;
		if (message[i] == 'u') aeiou[4]++;
	}

	printf("\nVowel count:\na: %i\ne: %i\ni: %i\no: %i\nu: %i", aeiou[0], aeiou[1], aeiou[2], aeiou[3], aeiou[4]);

	return 0;
}