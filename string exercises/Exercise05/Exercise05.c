/*
3. Write a program that asks user for a sentence and replace all the spaces
by two spaces.*/#include <stdio.h>
#include <string.h>  //gets

int main()
{
	char sentence[100] = { 0 };
	int sentenceLength = 0;

	printf("Write a sentence: ");
	gets(sentence);
	sentenceLength = strlen(sentence);

	printf("This is the new sentence:\n");
	for (int i = 0; i <= sentenceLength; i++)
	{
		if (sentence[i] == ' ') printf(" ");
		printf("%c", sentence[i]);
	}



	return 0;
}