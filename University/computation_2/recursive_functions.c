/*
 ========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 02, 2024;
 Name        : Recursive Functions Implementation;
 Source      : (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 Description : A C source file that implements functions for mathematical calculations,
               array manipulation, digit and bit manipulation, all using recursion.
 ========================================================================================
 */

#include "recursive_operations.h"

unsigned int fibonacci(unsigned int num)
{
    if (num <= 1)
    {
        return num;

    }

    return fibonacci(num - 1) + fibonacci(num - 2);
}

int digitReversalRecursive(int num, int rev)
{
    if (num == 0)
    {
        return rev;
    }
    return digitReversalRecursive(num / 10, rev * 10 + (num % 10));
}

int digitReversal(int num)
{
    return digitReversalRecursive(num, 0);
}

int sumArray(int v[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    return v[n - 1] + sumArray(v, n - 1);
}

int summation(unsigned int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n + summation(n - 1);
}

unsigned int raisedTo(unsigned int k, unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }

    return k * raisedTo(k, n - 1);
}

void arrayReversalRecursive(int v[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int temp = v[start];
    v[start] = v[end];
    v[end] = temp;

    arrayReversalRecursive(v, start + 1, end - 1);
}

void arrayReversal(int v[], int n)
{
    return arrayReversalRecursive(v, 0, n - 1);
}

int occurrences(unsigned int num, int digit)
{
    if (num == 0)
    {
        return 0;
    }

    int last_digit = num % 10, count = 0;

    if (last_digit == digit)
    {
        count++;
    }

    return count + occurrences(num / 10, digit);
}

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

int multip_rec(unsigned int n1, unsigned int n2)
{
    if (n1 == 0 || n2 == 0)
    {
        return 0;
    }

    if (n2 == 1)
    {
        return n1;
    }

    return n1 + multip_rec(n1, n2 - 1);
}

int arraySearchRecursive(int v[], int index, int num)
{
    if (index < 0)
    {
        return -1;
    }

    if (v[index] == num)
    {
        return index;
    }

    return arraySearchRecursive(v, index - 1, num);
}

int arraySearch(int v[], int n, int num)
{
    return arraySearchRecursive(v, n - 1, num);
}

int sumBits(unsigned int num)
{
    if (num == 0)
    {
        return 0;
    }
    return (num & 1) + sumBits(num >> 1);
}