/*
1. Write a program that asks user for a sentence and counts the number of
consonants and voweld contained.*/#include <stdio.h>
#include <string.h>

int main()
{
	char sentence[100] = { 0 };
	int sentenceLength = 0;
	int consonant = 0;
	int vowel = 0;

	printf("Write a sentence: ");
	gets(sentence);
	sentenceLength = strlen(sentence);

	for (int i = 0; i <= sentenceLength; i++)
	{
		if (sentence[i] == 'a') vowel++;
		else if (sentence[i] == 'e') vowel++;
		else if (sentence[i] == 'i') vowel++;
		else if (sentence[i] == 'o') vowel++;
		else if (sentence[i] == 'u') vowel++;
		else consonant++;
	}

	printf("Consonants: %i\nVowels: %i", consonant, vowel);

	return 0;
}