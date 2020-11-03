/*
1. Create an array containing the first 20 prime numbers
Print the result of the array using a for loop
Compute the total value of all numbers sumand print it.
*/

#include <stdio.h>

int main()
{
    int primeNumbers[20];
    int number = 0;
    int divider = 0;
    int count = 0;
    int primecount = 0;
    int sume = 0;

    printf("The first 20 prime numbers are: ");

    for (int i = 0; i < 20; i++)
    {
        while (primecount < 20)
        {
            count = 0;
            divider = 2;
            while (divider <= number / 2)
            {
                if (number % divider == 0) count++;
                divider++;
            }
            if (count == 0 && number != 1)
            {
                primeNumbers[i] = number;
                sume += primeNumbers[i];
                printf(" %i ", number);
                primecount++;
            }
            number++;
        }
    }

    printf("\n\nThe sume of all the numbers is: %i\n", sume);
    
    return 0;
}