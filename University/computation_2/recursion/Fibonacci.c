/*
 ========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 02, 2024;
 Name        : Fibonacci Sequence;
 Source      : (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 Description : C Program that calculates and returns the Nth term of the Fibonacci
               sequence.
 ========================================================================================
 */

#include <stdio.h>

int fibonacci(unsigned int N)
{
    if (N < 2)
    {
        return N;
    }
    else if (N > 1)
    {
        return fibonacci(N - 1) + fibonacci(N-2);
    }

    return 0;
}

int main()
{
    int n;
    printf("Input the Nth term of the Fibonacci Sequence:\n");
    scanf("%d", &n);

    printf("Nth term is: [%d]", fibonacci(n));
    return 0;
}