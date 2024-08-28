/*
 ========================================================================================
 Author      : Gabriel Hochmann
 Date        : August 28, 2024
 File        : static_list_1.h
 Source      : List in C (data structure) - Professor Rômulo Silva;
 Description : This file contains the header for a static list implementation in c.
 ========================================================================================
 */

#ifndef STATIC_LIST_1_H
#define STATIC_LIST_1_H

#define MAX_SIZE 1000 // Maximum number of Items in the static List

// ItemType represents the type of elements in the list. In this case, it's an int.
typedef int ItemType;

// Structure to a static list. Insertions are always made at the last free position.
// To delete an element at position i, all elements from position i+1 onwards are shifted left.
typedef struct
{
    ItemType items[MAX_SIZE]; // Array to store the elements of the list
    int free_position;         // Index of the next free position in the array
} StaticList;

/**
 * @brief Creates an empty static list.
 *
 * @return A pointer to the newly created empty static list.
 */
StaticList *create_empty_list();

/**
 * @brief Checks if the static list is empty.
 * 
 * @param list A pointer to the static list to check.
 * 
 * @return 1 if the list is empty, 0 otherwise.
*/
int is_empty(const StaticList *list);

/**
 * @brief Inserts an item into the static list.
 * 
 * The item is inserted at the next free positon. If the list is full, the item cannot be added.
 * 
 * @param list A pointer to the static list where the item will be inserted.
 * @param item The item to be inserted into the list.
 */
void insert(StaticList *list, ItemType item);

/**
 * @brief Removes an item from the static list.
 * 
 * To remove an item, all elements following the item are shifted left to fill the gap.
 * 
 * @param list A pointer to the static list from which the item will be removed.
 * @param item The item to be removed from the list.
 */
void remove_item(StaticList *list, ItemType item);

/**
 * @brief Prints all items in the static list.
 * 
 * @param list A pointer to the static list to be printed. 
*/
void print_list(StaticList *list);

#endif // STATIC_LIST_1_H