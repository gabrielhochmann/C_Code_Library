/*
 ========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 02, 2024;
 Name        : Power Calculator;
 Source      : (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 Description : A C Program that calculates the power of a k number..
 ========================================================================================
 */

#include <stdio.h>

int powerCalculator(int k, int n)
{
    if (n == 0)
    {
        return 1;
    };

    return k * powerCalculator(k, n - 1);
}

int main()
{
    int k, n;
    printf("Input two numbers (both greater than 0):\n");
    scanf("%d %d", &k, &n);

    printf("%d raised to the power of %d is: %d\n", k, n, powerCalculator(k, n));

    return 0;
}