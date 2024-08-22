/*
 ============================================================================================
 Author      : Gabriel Hochmann
 Date        : July 02, 2024
 File        : recursive_functions.c
 Description : A C source file that implements various recursive functions for mathematical
               calculations, array manipulation, digit and bit manipulation.
 Source      : Based on material from (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 ============================================================================================
 */

#include "recursive_functions.h"

/**
 * @brief Calculate the Fibonnaci number at a given position using recursion.
 *
 * @param num The position in the Fibonnaci sequence (non-negative).
 * @return unsigned int the Fibonnaci number at the given position.
 */
unsigned int fibonacci(unsigned int num)
{
    if (num <= 1)
    {
        return num;
    }

    return fibonacci(num - 1) + fibonacci(num - 2);
}

/**
 * @brief Helper function for digit reversal using recursion.
 *
 * @param num The number to be reversed (positive integer).
 * @param rev The reversed number constructed so far.
 * @return int The fully reversed number.
 */
int digitReversalRecursive(int num, int rev)
{
    if (num == 0)
    {
        return rev;
    }
    return digitReversalRecursive(num / 10, rev * 10 + (num % 10));
}

/**
 * @brief Reverse the digits of a number.
 *
 * @param num The number to be reversed (positive integer).
 * @return int The reversed number.
 */
int digitReversal(int num)
{
    return digitReversalRecursive(num, 0);
}

/**
 * @brief Calculate the sum of elements in an array using recursion.
 *
 * @param v The array of integers.
 * @param n The number of elements in the array (non-negative).
 * @return int The sum of the array elements.
 */
int sumArray(int v[], int n)
{
    if (n <= 0)
    {
        return 0;
    }

    return v[n - 1] + sumArray(v, n - 1);
}

/**
 * @brief Calculate the summation of all integers from 1 to n using recursion.
 *
 * @param n The upper limit of the summation (non-negative).
 * @return int The summation result.
 */
int summation(unsigned int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n + summation(n - 1);
}

/**
 * @brief Raise a number to a power using recursion
 *
 * @param k The base number.
 * @param n The exponent (non-negative).
 * @return unsigned int The result of k raised to the power of n.
 */
unsigned int raisedTo(unsigned int k, unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }

    return k * raisedTo(k, n - 1);
}

/**
 * @brief Helper function for array reversal using recursion.
 *
 * @param v The array to be reversed.
 * @param start The starting index for the reversal.
 * @param end The ending index for the reversal.
 */
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

/**
 * @brief Reverse the elements of an array.
 *
 * @param v The array to be reversed.
 * @param n The number of elements in the array (non-negative).
 */
void arrayReversal(int v[], int n)
{
    if (n > 0)
    {
        return arrayReversalRecursive(v, 0, n - 1);
    }
}

/**
 * @brief Count the ocurrences of a digit in a number using recursion.
 *
 * @param num The number to be checked.
 * @param digit The digit to count (0-9).
 * @return int The number of occurrences of the digit.
 */
int occurrences(unsigned int num, int digit)
{
    if (num == 0)
    {
        return (digit == 0) ? 1 : 0;
    }

    int last_digit = num % 10;
    int count = (last_digit == digit) ? 1 : 0;

    return count + occurrences(num / 10, digit);
}

/**
 * @brief Calculate the greatest commom divisor (GCD) of two numbers using recursion.
 *
 * @param x The first number.
 * @param y The second number.
 * @return int The GCD of the two numbers.
 */
int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

/**
 * @brief Multiply two numbers using recursion
 *
 * @param n1 The first number.
 * @param n2 The second number.
 *
 * @return int The product of the two numbers.
 */
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

/**
 * @brief Helper function for searching an element in an array using recursion.
 *
 * @param v The array to search.
 * @param index The current index to check.
 * @param num The number to search for.
 * @return int The index of the number if found, -1 otherwise.
 */
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

/**
 * @brief Search for a number in an array.
 *
 * @param v The array to search.
 * @param n The number of elements in the array.
 * @param num The number to search for.
 * @return int The index of the number if found, -1 otherwise.
 */
int arraySearch(int v[], int n, int num)
{
    return arraySearchRecursive(v, n - 1, num);
}

/**
 * @brief Calculate the sum of the bits in the binary representation of a number using recursion.
 *
 * @param num The number to be processed.
 * @return int The sum of the bits.
 */
int sumBits(unsigned int num)
{
    if (num == 0)
    {
        return 0;
    }
    return (num & 1) + sumBits(num >> 1);
}