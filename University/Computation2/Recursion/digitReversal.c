/*
 ========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 02, 2024;
 Name        : Digit Reversal;
 Source      : (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 Description : C Program that reverses a number N.
 ========================================================================================
 */

#include <stdio.h>

int digitRevert(int N, int reversedNumber)
{
    if (N == 0)
    {
        return reversedNumber;
    };

    int lastDigit = N % 10;
    N /= 10;

    reversedNumber = digitRevert(N, reversedNumber * 10 + lastDigit);

    return reversedNumber;
}

int main()
{
    int n;
    printf("Input a integer number (greatest than 0)\n");
    scanf("%d", &n);

    printf("Reverser Number is: [%d]\n", digitRevert(n, 0));

    return 0;
}