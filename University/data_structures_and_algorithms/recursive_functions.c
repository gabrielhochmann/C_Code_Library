/*
 ========================================================================================
 Author      : Gabriel Hochmann
 Date        : July 10, 2024
 File        : recursive_functions.c
 Source      : Recursion (List 1) - Professor Rômulo Silva
 Description : A C source file that implements recursive functions.
 ========================================================================================
 */

#include "recursive_functions.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

// Function to print numbers in ascending order recursively
void printNumbersAscending(int num)
{
    if (num > 1)
    {
        printNumbersAscending(num - 1);
        printf("%d\n", num - 1);
    }
}

// Function to print numbers in descending order recursively
void printNumbersDescending(int num)
{
    if (num > 1)
    {
        printf("%d\n", num - 1);
    }
    printNumbersDescending(num - 1);
}

// Function to calculate summation recursively
int summation(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n + summation(n - 1);
}

// Function to calculate factorial recursively
int factorial(unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

// Function to calculate super factorial recursively
int superFactorial(unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }

    return factorial(n) * superFactorial(n - 1);
}

// Function to calculate power recursively
unsigned int power(unsigned int base, unsigned int exp)
{
    if (exp == 0)
    {
        return 1;
    }

    return base * power(base, exp - 1);
}

// Function to calculate exponential factorial recursively
int exponentialFactorial(unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }

    return power(n, exponentialFactorial(n - 1));
}

/*
=================================================================================================
Catalan Number Implementations:
=================================================================================================
*/

/**
 * catalanNumber_1:
 * This implementation computes the nth Catalan number using the direct formula:
 * C(n) = (2n!) / ((n+1)! * n!)
 * 
 * Efficiency: This method is straightforward but limited by the factorial calculation.
 * For large n, calculating factorials can result in overflow and is computationally expensive
 * due to the large values involved.
 * 
 * It is accurate only for small values of n (up to n = 6).
 */
int catalanNumber_1(unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }

    return (factorial(2 * n)) / (factorial(n + 1) * factorial(n));
}

/**
 * catalanNumber_2:
 * This implementation computes the nth Catalan number using dynamic programming.
 * It recursively computes the sum of products of previously computed Catalan numbers.
 * 
 * Efficiency: This method is computationally expansive because it involves a double
 * recursive call that calculates the Catalan numbers for all values less than n.
 * It avoids factorial overflow issues but is inefficient for large values of n due to
 * repeated calculation.
 * 
 * It correctly computes up to n = 19.
 */
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

/**
 * catalanNumber_3:
 * This implementation computes the nth Catalan number using the recursive formula:
 * C(n) = (2*(2n-1)*C(n-1)) / (n+1)
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n) (due to recursion stack)
 * 
 * Efficiency: This method is theoretically faster than the dynamic programming approach
 * (catalanNumber_2) because it has a lower time complexity (O(n) vs. O(n²)). However,
 * due to the accumulation of rounding errors and integer overflow during the multiplication
 * and division operations, it is less precise for larger values of n.
 * 
 * It correctly computes up to n = 17.
 * 
 * In summary, while this method is faster for small values of n, it sacrifices precision
 * for larger n compared to the recursive dynamic programming method (catalanNumber_2).
 */

int catalanNumber_3(unsigned int n) // So so way, correctly computes up to n = 17
{
    if (n == 0)
    {
        return 1;
    }

    return (2 * (2 * n - 1) * catalanNumber_3(n - 1)) / (n + 1);
}

// Function to check if a string is palindrome recursively
int isPalindrome(const char *str, int len)
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

// Function to revert an array recursively
void revertArrayRecursive(int v[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int temp = v[end];
    v[end] = v[start];
    v[start] = temp;

    return revertArrayRecursive(v, start + 1, end - 1);
}

// Function to revert an array (wrapper function)
void revertArray(int v[], int n)
{
    revertArrayRecursive(v, 0, n - 1);
}

// Function to calculate Ackermann's function recursively
int ackermann(unsigned int m, unsigned int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (n == 0)
    {
        return ackermann(m - 1, 1);
    }
    else
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

// Function to sum digits of a number recursively
int sumDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return (n % 10) + sumDigits(n / 10);
};