/*
 ============================================================================================
 Author      : Gabriel Hochmann;
 Date        : July 02, 2024;
 File        : recursive_functions.h;
 Description : A C header file that declares functions for mathematical calculations,
               array manipulation, digit and bit manipulation, all using recursion.
 Source      : Based on material from (20240627, Aula2-3.pptx) - Teresinha Arnauts Hachisuca
 ============================================================================================
 */

#ifndef RECURSIVE_FUNCTIONS_H
#define RECURSIVE_FUNCTIONS_H

// Functions for mathematical calculations
unsigned int fibonacci(unsigned int num);
unsigned int raisedTo(unsigned int k, unsigned int n);
int gcd(int x, int y);
int multip_rec(unsigned int n1, unsigned int n2);
int summation(unsigned int n);

// Functions for array manipulation
int sumArray(int v[], int n);
void arrayReversal(int v[], int n);
int arraySearch(int v[], int n, int num);

// Functions for digit and bit manipulation
int digitReversal(int num);
int sumBits(unsigned int num);
int occurrences(unsigned int num, int digit);


#endif // RECURSIVE_FUNCTIONS_H