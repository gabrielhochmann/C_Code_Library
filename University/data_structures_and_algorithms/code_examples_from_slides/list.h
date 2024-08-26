/*
 ========================================================================================
 Author      : Gabriel Hochmann
 Date        : August 25, 2024
 File        : list.h
 Source      : List in C (data structure) - Professor Rômulo Silva;
 Description : This file contains the header of Static list in c.
 ========================================================================================
 */

#ifndef LIST_H
#define LIST_H

#define TAM_MAX 1000 // Maximum number of items in the list

// Type definition for items in the list
typedef int ItemType; // Example: using int as ItemType

// Type definition for the list
typedef struct {
    ItemType item[TAM_MAX]; // Array to hold the items
    int pos_free;          //  Position of the first free position in the list
} List;


// Create a void list
List *create_void_list();

// Test if the list is empty
int is_empty(List *list);

// Insert an item in the list
void insert_item(List *list, ItemType item);

// Remove an item from the list
void remove_item(List *list, ItemType item);

// Print the items in the list
void print_list(List *list);


#endif // LIST_H