/*
 ===========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 02, 2024;
 Name        : Sum of the bits of a positive number;
 Source      : (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca;
 Description : A C Program that calculates the bits sum of a number;
 ==========================================================================================
 */

#include <stdio.h>

int countBits(int n1, int count)
{
    if (n1 == 0)
    {
        return count;
    }

    count += n1 & 1;
    n1 = n1 >> 1;

    return countBits(n1, count);
}

int main()
{
    int n1, count = 0;

    printf("Input a integer and positive number:\n");
    scanf("%d", &n1);

    printf("The sum of bits is %d\n", countBits(n1, count));

    return 0;
}