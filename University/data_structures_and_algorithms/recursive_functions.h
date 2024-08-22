/*
 ========================================================================================
 Author      : Gabriel Hochmann
 Date        : July 10, 2024
 File        : recursive_functions.h
 Source      : Recursion (List 1) - Professor Rômulo Silva
 Description : Header file containing declarations for recursive functions used in various
               mathematical calculations, array manipulations, and string operations.
 ========================================================================================
 */

#ifndef RECURSION_FUNCTIONS_H
#define RECURSION_FUNCTIONS_H

/* Mathematical Calculations */
/**
 * Prints numbers in ascending order from 1 to num-1.
 * @param num The upper limit (exclusive) of the numbers to print.
 */
void printNumbersAscending(int num);

/**
 * Prints numbers in descending order from num-1 to 0.
 * @param num The upper limit (exclusive) of the numbers to print.
 */
void printNumbersDescending(int num);

/**
 * Calculates the sum of all integers from 0 to n recursively.
 * @param n The upper limit of the summation.
 * @return The sum of integers from 0 to n.
 */
int summation(int n);

/**
 * Calculates the factorial of a non-negative integer n recursively.
 * @param n The integer whose factorial is to be calculated.
 * @return The factorial of n.
 */
int factorial(unsigned int n);

/**
 * Calculates the super factorial of a non-negative integer n recursively.
 * @param n The integer whose super factorial is to be calculated.
 * @return The super factorial of n.
 */
int superFactorial(unsigned int n);

/**
 * Calculates the power of a base raised to an exponent recursively.
 * @param base The base value.
 * @param exp The exponent value.
 * @return The result of base raised to the power of exp.
 */
unsigned int power(unsigned int base, unsigned int exp);

/**
 * Calculates the exponential factorial of a non-negative integer n recursively.
 * @param n The integer whose exponential factorial is to be calculated.
 * @return The exponential factorial of n.
 */
int exponentialFactorial(unsigned int n);

/**
 * Calculates the nth Catalan number using the direct formula.
 * @param n The index of the Catalan number to be calculated.
 * @return The nth Catalan number.
 */
int catalanNumber_1(unsigned int n);

/**
 * Calculates the nth Catalan number using recursive dynamic programming.
 * @param n The index of the Catalan number to be calculated.
 * @return The nth Catalan number.
 */
int catalanNumber_2(unsigned int n);

/**
 * Calculates the nth Catalan number using a recursive formula.
 * @param n The index of the Catalan number to be calculated.
 * @return The nth Catalan number.
 */
int catalanNumber_3(unsigned int n);

/* Array Manipulation */
/**
 * Reverses the elements of an array recursively.
 * @param v The array to be reversed.
 * @param n The number of elements in the array.
 */
void revertArray(int v[], int n);

/* String Operations */
/**
 * Checks if a string is a palindrome recursively.
 * @param str The string to be checked.
 * @param len The length of the string.
 * @return 1 if the string is a palindrome, 0 otherwise.
 */
int isPalindrome(const char *str, int len);

/* Ackermann's Function */
/**
 * Calculates the Ackermann function recursively.
 * @param m The first parameter of the Ackermann function.
 * @param n The second parameter of the Ackermann function.
 * @return The result of the Ackermann function.
 */
int ackermann(unsigned int m, unsigned int n);

/* Digit Sum Calculation */
/**
 * Calculates the sum of the digits of a number recursively.
 * @param n The number whose digits are to be summed.
 * @return The sum of the digits of n.
 */
int sumDigits(int n);

#endif // RECURSIVE_FUNCTIONS_H
