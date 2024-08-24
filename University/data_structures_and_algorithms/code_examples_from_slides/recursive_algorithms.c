/*
 ========================================================================================
 Author      : Gabriel Hochmann
 Date        : August 24, 2024
 File        : recursive_algorithms.c
 Source      : Recursion in C - Professor Rômulo Silva;
 Description : This file contains various recursive algorithms, including examples of
               direct and indirect recursion, as well as tail recursion.
 ========================================================================================
 */

#include <stdio.h>

/**
 * Function: factorial
 * --------------------
 * Computes the factorial of a non-negative integer using direct recursion.
 *
 * Parameters:
 *  n: the non-negative integer whose factorial is to be computed.
 *
 * Returns:
 *  The factorial of n.
 */
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

/**
 * Function: fibonacci
 * --------------------
 * Computes the nth Fibonacci number using direct recursion.
 *
 * Parameters:
 *  n: the position in the Fibonacci sequence to compute.
 *
 * Returns:
 *  The nth Fibonacci number.
 */
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

/**
 * Fuction: greatestElem
 * ----------------------
 * Finds the greatest element in an array using recursion.
 *
 * Parameters:
 *  v: an array of integers.
 *  n: the size of the array.
 *
 * Returns:
 *  The greatest element in the array.
 */
int greatestElem(int v[], int n)
{
    if (n == 1)
    {
        return v[0];
    }
    else
    {
        int x = greatestElem(v, n - 1);
        if (x > v[n - 1])
        {
            return x;
        }
        else
        {
            return v[n - 1];
        }
    }
}

/**
 * Function: A
 * -----------------
 * Dummy function that performs some operations with an integer and a character.
 *
 * Parameters:
 *  param1: an integer parameter.
 *  param2: a character parameter.
 *
 * Returns:
 *  Some integer result.
 */
int A(int param1, char param2)
{
    // Implementation would go here

    return 0;
}

/**
 *  Function: B
 * ----------------
 * Process an array by calling function A for each element and accumulates the result.
 *
 * Parameters:
 *  v: an array of integers.
 *  n: the size of the array.
 *
 * Returns:
 *  An integer result based on the accumulation of calls to function A.
 */
int B(int v[], int n)
{
    int i, r = 0;
    for (i = 0; i < n; i++)
    {
        r += A(v[i], 'M'); // Calls function A
    }

    return r;
}

/**
 * Function: C
 * -----------------
 * Calls function B with a predefined vector of size 5.
 *
 * Returns:
 *  The result of function B.
 */
int C()
{
    int vector[5];
    // Vector initialization woul go here

    return B(vector, 5); // Calls function B
}

/**
 * Function: even
 * --------------------
 * Determines if a number is even using inderect recursion.
 *
 * Parameters:
 *  n: the integer to check.
 *
 * Returns:
 *  1 if the number is even, 0 otherwise.
 */
int even(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n > 0)
    {
        return odd(n - 1);
    }
    else
    {
        return even(-n);
    }
}

/**
 * Functio: odd
 * -------------------
 * Determines if a number is odd using inderect recursion.
 *
 * Parameters:
 *  n: the integer to check.
 *
 * Returns:
 *  1 if the number is odd, 0 otherwise.
 */
int odd(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n > 0)
    {
        return even(n - 1);
    }
    else
    {
        return odd(-n);
    }
}

/**
 * Function: factorial_tail
 * ------------------------------
 * Computes the factorial of a number using tail recursion.
 *
 * Parameters:
 *  n: the non-negative integer whose factorial is to be computed.
 *  accumulator: the accumulated value during recursion.
 *
 * Returns:
 *  The factorial of n.
 */
int factorial_tail(int n, int acumulator)
{
    if (n == 0)
    {
        return acumulator;
    }
    else
    {
        return factorial_tail(n - 1, n * acumulator); // Tail recursive call
    }
}

/**
 * Function: factorial (Tail Recursive Version)
 * ----------------------------------------------
 * Wrapper function that calls factorial_tail to compute the factorial using
 * tail recursion.
 *
 * Parameters:
 *  n: the non-negative integer whose factorial is to be computed.
 *
 * Returns:
 *  The factorial of n.
 */
int factorial_tail_recursion(int n)
{
    return factorial_tail(n, 1);
}