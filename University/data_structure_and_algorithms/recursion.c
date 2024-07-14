/*
 ========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 10, 2024;
 Name        : Recursive Functions Implementation;
 Source      : Recursion (List 1) - Professor Rômulo Silva;
 Description : A C source file that implements recursive functions.
 ========================================================================================
 */
#include "recursion.h"

void printNumbersAscending(int num)
{
    if (num > 1)
    {
        printNumbersAscending(num - 1);
        printf("%d\n", num - 1);
    }
}

void printNumbersDescending(int num)
{
    if (num > 1)
    {
        printf("%d\n", num - 1);
        printNumbersDescending(num - 1);
    }
}

int summation(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n + summation(n - 1);
}

int factorial(unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int superFactorial(unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }

    return factorial(n) * superFactorial(n - 1);
}

unsigned int power(unsigned int base, unsigned int exp)
{
    if (exp == 0)
    {
        return 1;
    }

    return base * power(base, exp - 1);
}

int exponentialFactorial(unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }

    return power(n, exponentialFactorial(n - 1));
}

int catalanNumber_1(unsigned int n) // Most inefficient way, correctly computes up to n = 6.
{
    if (n == 0)
    {
        return 1;
    }

    return (factorial(2 * n)) / (factorial(n + 1) * factorial(n));
}

int catalanNumber_2(unsigned int n) // Most efficient way, correctly computes up to n = 19
{
    if (n == 0)
    {
        return 1;
    }

    int sum = 0;
    for (unsigned int i = 0; i < n; ++i)
    {
        sum += catalanNumber_2(i) * catalanNumber_2(n - 1 - i);
    }
    return sum;
}

int catalanNumber_3(unsigned int n) // So so way, correctly computes up to n = 17
{
    if (n == 0)
    {
        return 1;
    }

    return (2 * (2 * n - 1) * catalanNumber_3(n - 1)) / (n + 1);
}

int isPalindrome(char *str, int len)
{
    if (len <= 1)
    {
        return 1;
    }

    if (*str != *(str + len - 1))
    {
        return 0;
    }

    return isPalindrome(str + 1, len - 2);
}

char *powerSet(char *orig, int len, char *conj)
{
    *orig = *conj;

    return conj;
}

int main()
{
    return 0;
}
