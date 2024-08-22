/*
 ========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : July 02, 2024;
 Name        : Recursive Operations Header;
 Source      : (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 Description : A C header file that declares functions for mathematical calculations,
               array manipulation, digit and bit manipulation, all using recursion.
 ========================================================================================
 */

#ifndef RECURSION_FUNCTIONS_H
#define RECURSION_FUNCTIONS_H

// Mathematical calculations
void printNumbersAscending(int num);
void printNumbersDescending(int num);
int summation(int n);
int factorial(unsigned int n);
int superFactorial(unsigned int n);
unsigned int power(unsigned int base, unsigned int exp);
int exponentialFactorial(unsigned int n);
int catalanNumber_1(unsigned int n);
int catalanNumber_2(unsigned int n);
int catalanNumber_3(unsigned int n);

// Array manipulation
void revertArray(int v[], int n);

// Function to check if a string is palindrome recursively
int isPalindrome(char *str, int len);

// Function to calculate Ackermann's function recursively
int ackermann(unsigned int m, unsigned int n);

// Function to sum digits of a number recursively
int sumDigits(int n);

#endif // RECURSIVE_FUNCTIONS_H
