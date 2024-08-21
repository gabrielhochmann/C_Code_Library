/*
 ========================================================================================
 Author      : Arkzesru (Gabriel Hochmann Alves);
 Date        : August 20, 2024;
 Name        : Pointer Functions Implementation;
 Source      : Pointers in C (List of Exercises) - Professor Rômulo Silva;
 Description : C source file that implements functions for various pointer operations,
               including statical calculations, vector copying, cloning, and comparison.
 ========================================================================================
 */

#include "pointer_functions.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Calculates the mode (most frequent element) in an integer array.
 *
 * @param v Array of integers.
 * @param n The number of elements in the Array.
 * @return The mode of the array, or -1 if the array is empty.
 */
int calculateMode(int *v, int n)
{
    if (n <= 0) {
        return -1; // Return -1 if the array is empty
    }

    // Find the maximum value in the array
    int maxValue = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > maxValue)
        {
            maxValue = v[i];
        }
    }

    // Allocate memory to store frequency counts
    int *counts = (int *)calloc(maxValue + 1, sizeof(int));
    if (counts == NULL)
    {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    // Count the frequency of each value in the array
    for (int i = 0; i < n; i++)
    {
        counts[v[i]]++;
    }

    // Find the mode by checking the maximum frequency
    int mode = v[0];
    int maxCount = 0;
    for (int i = 0; i <= maxValue; i++)
    {
        if (counts[i] > maxCount)
        {
            maxCount = counts[i];
            mode = i;
        }
    }

    free(counts); // Free allocated memory
    return mode;
}

/**
 * @brief Calculates various statistics for an integer array.
 *
 * @param v Array of integers.
 * @param n The number of elements in the array.
 * @param mode Pointer to store the mode (most frequent element).
 * @param smallest Pointer to store the smallest value.
 * @param greatest Pointer to store the greatest value.
 * @param average Pointer to store the average of the array.
 * @return The sum of the elements in the array.
 */
int calculate_statistics(int v[], int n, int *mode, int *smallest, int *greatest, float *average)
{
    // Edge case: empty array
    if (n <= 0)
    {
        fprintf(stderr, "Error: The array is empty.\n");
        return 0;
    }

    // Initialize sum and extreme values
    int sum = 0;
    *smallest = v[0];
    *greatest = v[0];

    // Calculate sum, smallest, and greatest value in a single loop
    for (int i = 0; i < n; i++)
    {
        sum += v[i];

        if ((*smallest) > v[i])
        {
            *smallest = v[i];
        }

        if ((*greatest) < v[i])
        {
            *greatest = v[i];
        }
    }

    // Calculate mode using a helper function
    *mode = calculateMode(v, n);

    // Calculate the average
    *average = (float)sum / n;

    // Return the total sum
    return sum;
}

/**
 * Copies n elements from vetA to vetB.
 * 
 * @param vetA The source array to copy from.
 * @param vetB the destination array to copy to.
 * @param n The number of elements to copy.
 */
void copy_vector(const int vetA[], int vetB[], int n)
{
    for (int i = 0; i < n; i++)
    {
        vetB[i] = vetA[i];
    }
}

/**
 * Creates a new array as a replica of the input array.
 * Allocates memory dynamically, so the caller is responsible
 * for freeing the allocated memory after use.
 * 
 * @param vet The source array to replicate.
 * @param n   The number of elements in the array.
 * @return    A pointer to the newly allocated array containing a copy
 *            of the input Array.
 *            If memory allocation fails, the program will exit.
 */
int *clone_vector(int src[], int n)
{
    int *clone = (int *) malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (clone == NULL) {
        perror("Failed to allocate memory.");
        exit(EXIT_FAILURE);
    }

    // Copy elements from the source array to the new array
    for (int i = 0; i < n; i++)
    {
        clone[i] = src[i];
    }

    return clone;
}

/**
 * @brief Sorts three integer values pointed to by 'a', 'b', and 'c' in ascending order.
 * 
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 * @param c Pointer to the third integer.
 * 
 * @return 1 if all values are equal, otherwise 0.
 */
int comparator(int *a, int *b, int *c) {
    int temp;
    
    // Ensure *a <= *b
    if (*a > *b) {
        temp = *b;
        *b = *a;
        *a = temp;
    } 

    // Ensure *n <= *c
    if (*b > *c) {
        temp = *c;
        *c = *b;
        *b = temp;
    }

    // Final check to ensure *a <= *c
    if (*a > *c) {
        temp = *c;
        *c = *a;
        *a = temp;
    }

    // Return 1 if all values are equal, otherwise return 0
    return (*a == *b && *b == *c);
}
