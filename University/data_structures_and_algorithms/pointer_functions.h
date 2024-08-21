/*
 ========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves)
 Date        : August 20, 2024
 Name        : Pointer Functions
 Source      : Pointers in C (List of Exercises) - Professor Rômulo Silva
 Description : A C header file that declares several functions for handling arrays and
               performing operations using pointers.
 ========================================================================================
 */

#ifndef POINTERS_FUNCTIONS_H
#define POINTERS_FUNCTIONS_H

// Calculates the mode of an integer array 'v'with size 'n'.
// Returns the mode (most most frequent element) of the array.
int calculateMode(int *v, int n);

// Calculates various statistics for an integer array 'v' with size 'n'.
// Outputs: mode, smallest value, greatest value, and average via pointer parameter.
// Returns the sum of all elements in the array.
int calculate_statistics(int v[], int n, int *mode, int *smallest, int *greatest, float *average);

// Copies the contents of an integer array 'vetA' to another array 'vetB' with size 'n'.
void copy_vector(const int vetA[], int vetB[], int n);

// Clones the vector 'vet' of size 'n' and returns a dynamically allocated copy.
int *clone_vector(int vet[], int n);

// Compares and sorts three integer pointers 'a', 'b', and 'c' in ascending order.
// Returns 1 if all values are equal, 0 otherwise.
int comparator(int *a, int *b, int *c);

#endif // POINTERS_FUNCTIONS_H