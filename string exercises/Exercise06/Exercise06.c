/*
4. Write a program that asks user for a sentence and count the times that
word "the" appears.
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char sentence[100] = { 0 };
	int sentenceLength = 0;
	int theCount = 0;

	printf("Write a sentence: ");
	gets(sentence);
	sentenceLength = strlen(sentence);

	for (int i = 0; i <= sentenceLength; i++)
	{
		if ((sentence[i] == 't'&&sentence[i+1]=='h')&&sentence[i+2]=='e') theCount++;
	}

	printf("The word ''the'' appears %i times", theCount);

	return 0;
}