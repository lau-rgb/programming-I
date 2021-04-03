/*
5. Write a program that asks user for a sentence and count how many words
it contains. Print the first letter of every word.
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char sentence[100] = { 0 };
	int sentenceLength = 0;
	int words = 1;

	printf("Write a sentence: ");
	gets(sentence);
	sentenceLength = strlen(sentence);

	printf("First letter of each word: ");
	for (int i = 0; i <= sentenceLength; i++)
	{
		if (sentence[i] == ' ')
		{
			words++;
			printf("%c ", sentence[i + 1]);
		}
	}

	printf("\nThere are %i words", words);

	return 0;
}