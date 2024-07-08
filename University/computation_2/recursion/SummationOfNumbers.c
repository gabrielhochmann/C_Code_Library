/*
 ========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 02, 2024;
 Name        : Summation Of Numbers;
 Source      : (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 Description : A C Program that calculates the summation of numbers 1 to N.
 ========================================================================================
 */

#include <stdio.h>

int summation(int n)
{
    if (n > 0)
    {
        return n + summation(n - 1);
    };

    return 0;
}

int main()
{
    int n;
    printf("Input a number:\n");
    scanf("%d", &n);

    printf("Summation from 1 to %d is: %d\n", n, summation(n));

    return 0;
}