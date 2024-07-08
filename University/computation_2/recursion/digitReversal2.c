/*
 ========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 02, 2024;
 Name        : Digit Reversal version 2;
 Source      : (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 Description : C Program that reverses a number N.
 ========================================================================================
 */

#include <stdio.h>
#include <math.h>

int digitRevert(int N)
{
    int p = log10(N);

    if (N > 0)
    {
        return N % 10 * pow(10, p) + digitRevert( N / 10);
    }
    return 0;
}

int main()
{
    int n;
    printf("Input a integer number (greatest than 0)\n");
    scanf("%d", &n);

    printf("Reverser Number is: [%d]\n", digitRevert(n));

    return 0;
}
