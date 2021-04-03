/*
3. Write a program that asks user for a sentence and copy it to another
string replacing every vowel by a point '.'. Print the result string on the
screen.
*/

#include <stdio.h>
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
		if (sentence[i] == 'a') sentence[i] = '.';
		if (sentence[i] == 'e') sentence[i] = '.';
		if (sentence[i] == 'i') sentence[i] = '.';
		if (sentence[i] == 'o') sentence[i] = '.';
		if (sentence[i] == 'u') sentence[i] = '.';
		printf("%c", sentence[i]);
	}



	return 0;
}