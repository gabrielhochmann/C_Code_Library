/*
 ========================================================================================
 Author      : Gabriel Hochmann
 Date        : August 23, 2024
 File        : pointers.c
 Source      : Pointers in C - Professor Rômulo Silva;
 Description : C source file containing code examples from the lecture slide "Ponteiros",
               demonstrating various pointer operations such as allocation, deallocation,
               manipulation, and pointer arithmetic. Includes examples of pointer types,
               dynamic memory allocation, pointer arithmetic, and bidimensional arrays.
 ========================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcpy

int main(void)
{
    // Declaration of pointers
    int *p1;  // Pointer to int
    char *ch; // Pointer to char

    typedef struct
    {
        int studentID;
        char name[30];
    } Student;

    Student *a1; // Pointer to Student struct

    // Allocation and deallocation of memory
    p1 = (int *)malloc(sizeof(int)); // Allocate memory for an int
    if (p1 == NULL)
    {
        /* Handle memory allocation failure */
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    *p1 = 7; // Assign value to the allocated int

    a1 = (Student *)malloc(sizeof(Student)); // Allocate memory for a Student
    if (a1 == NULL)
    {
        /* Handle memory allocation failure */
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    a1->studentID = 1234;
    strcpy(a1->name, "Gabriel Hochmann");

    ch = (char *)malloc(10 * sizeof(char)); // Allocate memory for an array of char
    if (ch == NULL)
    {
        /* Handle memory allocation failure */
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    strcpy(ch, "example");
    printf("String: %s\n", ch);

    free(ch); // Deallocate memory pointed to by ch

    free(p1); // Deallocate memory pointed to by p1
    p1 = NULL;
    free(a1); // Deallocate memory pointed to by a1
    a1 = NULL;

    // Obtaining address of a variable
    int n1 = 7;
    int *ptr = &n1; // ptr points to the addres of n1
    *ptr = 11;      // n1 is now 11

    // Array and pointer arithmetic

    /**
     * v[i] and *(v + i) access the value of the element at position i.
     * &v[i] gives the address of the element at index i.
     * v + i also gives the address of the element at index i.
     */

    int v[3]; // Array with 3 elements
    v[0] = 37;
    *(v + 1) = 7; // v[1] contains the value 7
    v[2] = 9;
    printf("The address of the element of index 2: %p\n", (void *)(v + 2));

    // Pointers arithmetic example
    int *v_dynamic = (int *)malloc(5 * sizeof(int)); // Dynamic array with 5 elements
    if (v_dynamic == NULL)
    {
        /* Handle memory allocation failure */
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    int *ptr2 = v_dynamic; //  ptr2 points to v_dynamic[0];
    *ptr2 = 7;             // v_dynamic[0] = 7;
    ptr2++;
    *ptr2 = 11; // v_dynamic[1] = 11
    ptr2++;
    *ptr2 = 29; // v_dynamic[2] = 29
    ptr2--;
    *ptr2 = 17; // v_dynamic[1] = 17

    // Bidimensional matrices (arrays of arrays)

    int **mat; // Pointer to pointer (double pointer)
    int m = 5; // Number of rows
    int n = 7; // Number of columns
    int i, j;

    mat = (int **)malloc(m * sizeof(int *)); // Allocate array of pointers
    if (mat == NULL)
    {
        /* Handle memory allocation failure */
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < m; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int)); // Allocate array of integers for each row
        if (mat[i] == NULL)
        {
            /* Handle memory allocation failure */
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]); // Access mat[i][j]
        }
        printf("\n");
    }

    // Free allocated memory
    for (i = 0; i < m; i++)
    {
        free(mat[i]); // Free each row
    }
    free(mat); // Free the array of pointers

    return 0;
}
