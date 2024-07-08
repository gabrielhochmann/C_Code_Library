/*
 ========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 02, 2024;
 Name        : Greatest Commom Divisor;
 Source      : (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 Description : A C Program that calculates the GCD of two numbers.
 ========================================================================================
 */

#include <stdio.h>

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x % y);
    }
}

int main()
{
    int x, y;

    printf("Input two numbers to find the GDC:\n");
    scanf("%d %d", &x, &y);

    printf("The GCD of %d and %d is %d\n", x, y, gcd(x, y));

    return 0;
}