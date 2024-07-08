/*
 ===========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 02, 2024;
 Name        : Number of occurrences of a natural number;
 Source      : (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 Description : A C Program that counts the occurrences of a natural number in other number.
 ==========================================================================================
 */

#include <stdio.h>

int counter(int k, int n, int count)
{
    if (n <= 0)
    {
        return count;
    }

    int digit = n % 10;

    if (k == digit) {
        count++;
    }

    n /= 10;

    return counter(k, n, count);
}

int main()
{
    int k, n, count = 0;

    printf("Input a digit:\n");
    scanf("%d", &k);

    printf("Input a natural number:\n");
    scanf("%d", &n);

    printf("The number of occurrences of %d in %d is %d\n", k, n, counter(k, n, count));

    return 0;
}