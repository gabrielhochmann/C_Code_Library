/*
 ===========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 02, 2024;
 Name        : Successive Sums;
 Source      : (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 Description : A C Program that performs multiplication through sucessive additions using
               recursion.
 ==========================================================================================
 */

#include <stdio.h>

int mult_rec(int n1, int n2)
{
    if (n1 == 0)
    {
        return 0;
    }

    return n2 + mult_rec(n1 - 1, n2);
}

int main()
{
    int n1, n2;

    printf("Input two numbers:\n");
    scanf("%d %d", &n1, &n2);

    printf("The result is %d\n", mult_rec(n1, n2));

    return 0;
}